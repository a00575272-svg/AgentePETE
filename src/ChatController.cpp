#include "ChatController.h"
#include "Prompt.h"
#include "PeteExceptions.h"
#include "Task.h"

#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <filesystem>

ChatController::ChatController() {}
ChatController::~ChatController() {}

bool ChatController::tryParseAndCreateTask(const QString &rawPrompt, QString &outMessage)
{
    const QString lower = rawPrompt.toLower();
    const QStringList keywords = {
        "crear tarea", "crea tarea", "crea una tarea", "crear una tarea",
        "agrega tarea", "agrega una tarea", "añade tarea", "nueva tarea",
        "recuérdame", "recuerdame", "anota que", "agenda que",
        "añadir tarea", "registra tarea"
    };

    bool hasIntent = false;
    for (const QString &kw : keywords) {
        if (lower.contains(kw)) { hasIntent = true; break; }
    }
    if (!hasIntent)
        return false;

    QDate today = QDate::currentDate();
    const QString extractionPrompt = QString(
        "Eres un extractor de datos. Del texto del usuario extrae ÚNICAMENTE un JSON con estos campos:\n"
        "- title: título corto de la tarea (máximo 50 caracteres)\n"
        "- description: descripción breve de la tarea\n"
        "- day: día como número entero (1-31)\n"
        "- month: mes como número entero (1-12)\n"
        "- year: año como número entero de 4 dígitos\n\n"
        "Si el texto no menciona fecha, usa la fecha de hoy: %1/%2/%3\n\n"
        "Texto del usuario: \"%4\"\n\n"
        "Responde ÚNICAMENTE con JSON válido, sin texto extra, sin bloques de código:\n"
        "{\"title\": \"...\", \"description\": \"...\", \"day\": N, \"month\": N, \"year\": N}"
    ).arg(today.day()).arg(today.month()).arg(today.year()).arg(rawPrompt);

    QString jsonResponse;
    try {
        jsonResponse = ollamaProvider_.enviarMensaje(extractionPrompt);
    } catch (...) {
        return false;
    }

    // Limpiar bloques markdown si el modelo los devuelve
    jsonResponse = jsonResponse.trimmed();
    if (jsonResponse.startsWith("```json"))
        jsonResponse = jsonResponse.mid(7);
    else if (jsonResponse.startsWith("```"))
        jsonResponse = jsonResponse.mid(3);
    if (jsonResponse.endsWith("```"))
        jsonResponse.chop(3);
    jsonResponse = jsonResponse.trimmed();

    // Extraer solo el bloque JSON si hay texto extra alrededor
    const int braceStart = jsonResponse.indexOf('{');
    const int braceEnd   = jsonResponse.lastIndexOf('}');
    if (braceStart != -1 && braceEnd != -1 && braceEnd > braceStart)
        jsonResponse = jsonResponse.mid(braceStart, braceEnd - braceStart + 1);

    QJsonParseError parseError;
    const QJsonDocument doc = QJsonDocument::fromJson(jsonResponse.toUtf8(), &parseError);
    if (parseError.error != QJsonParseError::NoError || !doc.isObject())
        return false;

    const QJsonObject obj = doc.object();
    if (!obj.contains("title") || !obj.contains("day") || !obj.contains("month") || !obj.contains("year"))
        return false;

    const QString title       = obj["title"].toString().trimmed();
    const QString description = obj["description"].toString().trimmed();
    const int day   = obj["day"].toInt();
    const int month = obj["month"].toInt();
    const int year  = obj["year"].toInt();

    if (title.isEmpty() || day < 1 || day > 31 || month < 1 || month > 12 || year < 2000)
        return false;

    std::filesystem::create_directories("taskDir");
    Task task(day, month, year, title.toStdString(), description.toStdString());

    outMessage = QString("Tarea creada: \"%1\" para el %2/%3/%4")
                     .arg(title)
                     .arg(day,   2, 10, QChar('0'))
                     .arg(month, 2, 10, QChar('0'))
                     .arg(year);
    return true;
}

QString ChatController::processPrompt(const QString &rawPrompt)
{
    try {
        Prompt prompt(rawPrompt);
        if (!prompt.isValid())
            return prompt.validationError();

        QString taskMsg;
        if (tryParseAndCreateTask(rawPrompt, taskMsg))
            return taskMsg;

        return ollamaProvider_.enviarMensaje(prompt.ollamaPrompt());
    } catch (const PromptVacioException &e) {
        return QString("[Error] ") + e.what();
    } catch (const ErrorConexionException &e) {
        return QString("[Error de conexión] ") + e.what();
    } catch (const JsonInvalidoException &e) {
        return QString("[Error de respuesta] ") + e.what();
    } catch (const std::exception &e) {
        return QString("[Error inesperado] ") + e.what();
    }
}

QString ChatController::preparePromptForOllama(const QString &rawPrompt) const
{
    Prompt prompt(rawPrompt);

    if (!prompt.isValid())
        return "";

    return prompt.ollamaPrompt();
}

QString ChatController::buildSimulatedResponse(const Prompt &prompt) const
{
    const QString lower = prompt.text().toLower();

    if (containsKeyword(lower, "hola"))
        return "[Simulado] ¡Hola! Soy AgentePETE, tu asistente personal. ¿En qué te puedo ayudar hoy?";

    if (containsKeyword(lower, "recordar") || containsKeyword(lower, "recuérdame"))
        return "[Simulado] Entendido, anotaré eso como un recordatorio. (Función completa disponible en próxima sesión.)";

    if (containsKeyword(lower, "calendario") || containsKeyword(lower, "evento"))
        return "[Simulado] Revisando tu calendario... Función de calendario en desarrollo. ¡Pronto disponible!";

    if (containsKeyword(lower, "tarea") || containsKeyword(lower, "pendiente"))
        return "[Simulado] He registrado tu tarea en la lista de pendientes. ¡La gestionaremos juntos!";

    return "[Simulado] Recibido. Aún estoy aprendiendo a manejar ese tipo de solicitud. ¡Seguimos mejorando!";
}

bool ChatController::containsKeyword(const QString &text, const QString &keyword) const
{
    return text.contains(keyword, Qt::CaseInsensitive);
}
