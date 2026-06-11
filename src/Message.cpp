#include "Message.h"

Message::Message()
    : sender_(Sender::System)
    , content_("")
    , validationError_("El mensaje no puede estar vacío.")
{
}

Message::Message(Sender sender, const QString &content)
    : sender_(sender)
{
    setContent(content);
}

Message::Sender Message::sender() const
{
    return sender_;
}

QString Message::content() const
{
    return content_;
}

QString Message::validationError() const
{
    return validationError_;
}

bool Message::isValid() const
{
    return !content_.isEmpty() && validationError_.isEmpty();
}

bool Message::setContent(const QString &content)
{
    const QString cleanedContent = content.simplified();

    if (cleanedContent.isEmpty()) {
        content_.clear();
        validationError_ = "El mensaje no puede estar vacío.";
        return false;
    }

    if (cleanedContent.length() > maxLength()) {
        content_.clear();
        validationError_ = QString("El mensaje no puede superar %1 caracteres.").arg(maxLength());
        return false;
    }

    content_ = cleanedContent;
    validationError_.clear();
    return true;
}

QString Message::senderName() const
{
    switch (sender_) {
    case Sender::User:
        return "Tú";
    case Sender::Assistant:
        return "AgentePETE";
    case Sender::System:
        return "Sistema";
    case Sender::Error:
        return "Error";
    }

    return "Sistema";
}

QString Message::toDisplayString() const
{
    const QString safeContent = content_.isEmpty() ? "(sin contenido)" : content_;
    return senderName() + ": " + safeContent;
}

Message Message::fromUser(const QString &content)
{
    return Message(Sender::User, content);
}

Message Message::fromAssistant(const QString &content)
{
    return Message(Sender::Assistant, content);
}

Message Message::system(const QString &content)
{
    return Message(Sender::System, content);
}

Message Message::error(const QString &content)
{
    return Message(Sender::Error, content);
}

int Message::maxLength()
{
    return 2000;
}
