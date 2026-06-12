#pragma once

#include "Conversation.h"

class ConversationStats {
public:
    static int totalMessages(const Conversation& conversation);

    static int totalUserMessages(const Conversation& conversation);

    static int totalAssistantMessages(const Conversation& conversation);

    static int totalSystemMessages(const Conversation& conversation);

    static int totalErrorMessages(const Conversation& conversation);
};
