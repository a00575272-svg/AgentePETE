#include "ConversationStats.h"

int ConversationStats::totalMessages(const Conversation& conversation)
{
    return conversation.size();
}

int ConversationStats::totalUserMessages(const Conversation& conversation)
{
    return conversation.messagesBySender(Message::Sender::User).size();
}

int ConversationStats::totalAssistantMessages(const Conversation& conversation)
{
    return conversation.messagesBySender(Message::Sender::Assistant).size();
}

int ConversationStats::totalSystemMessages(const Conversation& conversation)
{
    return conversation.messagesBySender(Message::Sender::System).size();
}

int ConversationStats::totalErrorMessages(const Conversation& conversation)
{
    return conversation.messagesBySender(Message::Sender::Error).size();
}
