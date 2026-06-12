#include "ChatController.h"
#include "Prompt.h"
#include "PeteExceptions.h"

ChatController::ChatController() {}
ChatController::~ChatController() {}

QString ChatController::processPrompt(const QString &rawPrompt)
{
    try {
        Prompt prompt(rawPrompt);
        if (!prompt.isValid())
            return prompt.validationError();
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
