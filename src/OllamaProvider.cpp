// ============================================================
//  OllamaProvider.cpp
//  Módulo de comunicación con Ollama usando Qt Network
//
//  Equivalente al ollama_chat.cpp de Manolo, pero usando
//  QNetworkAccessManager en lugar de libcurl y
//  QJsonDocument en lugar de nlohmann/json.
// ============================================================

#include "OllamaProvider.h"
#include "PeteExceptions.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QTimer>

// ─────────────────────────────────────────────
//  CONFIGURACIÓN GLOBAL
// ─────────────────────────────────────────────

// URL de la API local de Ollama
const QString OllamaProvider::OLLAMA_URL = "http://localhost:11434/api/generate";


OllamaProvider::OllamaProvider(QObject *parent)
    : QObject(parent)
    , modelo_("gemma4")   // Modelo por defecto (fácil de cambiar)
{
}

void OllamaProvider::setModelo(const QString &modelo)
{
    modelo_ = modelo;
}

QString OllamaProvider::modelo() const
{
    return modelo_;
}


// ─────────────────────────────────────────────
//  FUNCIÓN: enviarMensaje
//
//  Parámetro:  mensaje  → texto que escribió el usuario
//  Retorna:    QString  → respuesta de la IA, o mensaje de error
// ─────────────────────────────────────────────
QString OllamaProvider::enviarMensaje(const QString &mensaje)
{
    // 1. Construir el JSON que Ollama espera recibir
    QJsonObject cuerpo;
    cuerpo["model"]  = modelo_;
    cuerpo["prompt"] = mensaje;
    cuerpo["stream"] = false;   // false = esperar respuesta completa antes de recibirla

    // 1.1. Definir la configuracion del modelo
    QJsonObject options;
    options["num_predict"] = 1024;

    cuerpo["options"] = options;

    QByteArray jsonBytes = QJsonDocument(cuerpo).toJson(QJsonDocument::Compact);

    // 2. Configurar la petición HTTP
    QUrl url(OLLAMA_URL);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 3. Enviar la petición (POST)
    QNetworkReply *reply = networkManager_.post(request, jsonBytes);

    // 4. Esperar la respuesta de forma síncrona usando QEventLoop
    //    (equivalente a curl_easy_perform)
    QEventLoop loop;
    QTimer timeout;

    timeout.setSingleShot(true);
    timeout.setInterval(120000);   // Tiempo máximo total: 120 segundos

    connect(reply,    &QNetworkReply::finished, &loop, &QEventLoop::quit);
    connect(&timeout, &QTimer::timeout,         &loop, &QEventLoop::quit);

    timeout.start();
    loop.exec();

    // 5. Revisar si hubo error de conexión
    if (reply->error() != QNetworkReply::NoError) {
        const QString errorMsg = reply->errorString();
        reply->deleteLater();

        // Mensaje de error amigable según el tipo de fallo
        if (reply->error() == QNetworkReply::ConnectionRefusedError) {
            throw ErrorConexionException("¿Está Ollama abierto? Ejecuta: ollama serve");
        }
        return "[ERROR] Fallo en la petición HTTP: " + errorMsg;
    }

    // 6. Leer la respuesta HTTP
    const QByteArray respuestaHTTP = reply->readAll();
    reply->deleteLater();

    // 7. Parsear el JSON de respuesta
    QJsonParseError parseError;
    const QJsonDocument respuestaJSON = QJsonDocument::fromJson(respuestaHTTP, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        throw JsonInvalidoException(parseError.errorString().toStdString());
    }

    const QJsonObject obj = respuestaJSON.object();

    // Verificar que el campo "response" exista
    if (!obj.contains("response")) {

        // Verificar si Ollama devolvió un error (modelo no instalado, etc.)
        if (obj.contains("error")) {
            const QString errOllama = obj["error"].toString();
            return "[ERROR de Ollama] " + errOllama +
                   "\n  → ¿Está instalado el modelo? Ejecuta: ollama pull " + modelo_;
        }

        return "[ERROR] La respuesta no contiene el campo 'response'.\n"
               "  Respuesta recibida: " + QString::fromUtf8(respuestaHTTP);
    }

    // Extraer y retornar la respuesta de la IA
    return obj["response"].toString();
}
