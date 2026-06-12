#include "Prompt.h"
#include "PeteExceptions.h"

Prompt::Prompt()
    : text_("")
    , validationError_("El prompt no puede estar vacío.")
{
}

Prompt::Prompt(const QString &rawText)
{
    setText(rawText);
}

bool Prompt::setText(const QString &rawText)
{
    const QString cleanedText = normalize(rawText);

    if (cleanedText.isEmpty()) {
        text_.clear();
        validationError_ = "El prompt no puede estar vacío.";
        throw PromptVacioException();
        return false;
    }

    if (cleanedText.length() > maxLength()) {
        text_.clear();
        validationError_ = QString("El prompt no puede superar %1 caracteres.").arg(maxLength());
        return false;
    }

    text_ = cleanedText;
    validationError_.clear();
    return true;
}

QString Prompt::text() const
{
    return text_;
}

QString Prompt::ollamaPrompt() const
{
    if (!isValid())
        return "";

    return systemInstruction()
        + "\n\nSolicitud del usuario:\n"
        + text_
        + "\n\nRespuesta esperada:\n";
}

bool Prompt::isValid() const
{
    return !text_.isEmpty() && validationError_.isEmpty();
}

QString Prompt::validationError() const
{
    return validationError_;
}

int Prompt::maxLength()
{
    return 50000;
}

QString Prompt::normalize(const QString &rawText)
{
    return rawText.simplified();
}

QString Prompt::systemInstruction()
{
    return "Eres AgentePETE, un asistente personal de organización. "
           "Responde en español, de forma breve, clara y útil. "
           "Si el usuario pide una tarea, recordatorio o evento, identifica la intención principal, "
           "extrae la información importante y responde con una acción o confirmación entendible. "
           "Si falta información, pide solo el dato necesario.";
}
