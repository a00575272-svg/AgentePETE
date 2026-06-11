#pragma once

#include <QString>

class Message {
public:
    enum class Sender {
        User,
        Assistant,
        System,
        Error
    };

    Message();
    Message(Sender sender, const QString &content);

    Sender sender() const;
    QString content() const;
    QString validationError() const;
    bool isValid() const;

    bool setContent(const QString &content);
    QString senderName() const;
    QString toDisplayString() const;

    static Message fromUser(const QString &content);
    static Message fromAssistant(const QString &content);
    static Message system(const QString &content);
    static Message error(const QString &content);
    static int maxLength();

private:
    Sender sender_;
    QString content_;
    QString validationError_;
};
