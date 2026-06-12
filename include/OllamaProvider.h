#pragma once

// ============================================================
//  OllamaProvider.h
//  Módulo de comunicación con Ollama usando Qt Network
//
//  Reemplaza libcurl por QNetworkAccessManager para
//  integrarse nativamente con el proyecto Qt.
// ============================================================

#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class OllamaProvider : public QObject
{
    Q_OBJECT

public:
    explicit OllamaProvider(QObject *parent = nullptr);

    // Envía un prompt a Ollama y retorna la respuesta como QString.
    // Si hay error de conexión o JSON inválido, retorna un mensaje de error.
    QString enviarMensaje(const QString &mensaje);

    // Modelo a usar (fácil de cambiar)
    void setModelo(const QString &modelo);
    QString modelo() const;

private:
    // ─────────────────────────────────────────────
    //  URL de la API local de Ollama
    // ─────────────────────────────────────────────
    static const QString OLLAMA_URL;

    QString modelo_;
    QNetworkAccessManager networkManager_;
};
