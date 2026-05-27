#include "ChatController.h"

QString ChatController::processPrompt(const QString &prompt) const
{
    if (prompt.trimmed().isEmpty())
        return "[Simulado] Por favor escribe algo para que pueda ayudarte.";

    const QString lower = prompt.toLower();

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
