#pragma once

#include <QVector>
#include "Message.h"

class Conversation {
public:
    Conversation();

    void addMessage(const Message& message);

    QVector<Message> messages() const;

    QVector<Message> messagesBySender(Message::Sender sender) const;

    Message lastMessage() const;

    int size() const;

    bool isEmpty() const;

    void clear();

private:
    QVector<Message> messages_;
};
