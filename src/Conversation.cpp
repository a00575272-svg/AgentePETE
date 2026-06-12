#include "Conversation.h"

Conversation::Conversation()
{
}

void Conversation::addMessage(const Message& message)
{
    messages_.append(message);
}

QVector<Message> Conversation::messages() const
{
    return messages_;
}

QVector<Message> Conversation::messagesBySender(Message::Sender sender) const
{
    QVector<Message> filteredMessages;

    for (const Message& message : messages_)
    {
        if (message.sender() == sender)
        {
            filteredMessages.append(message);
        }
    }

    return filteredMessages;
}

Message Conversation::lastMessage() const
{
    if (messages_.isEmpty())
    {
        return Message();
    }

    return messages_.last();
}

int Conversation::size() const
{
    return messages_.size();
}

bool Conversation::isEmpty() const
{
    return messages_.isEmpty();
}

void Conversation::clear()
{
    messages_.clear();
}
