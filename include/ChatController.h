#pragma once

#include <QString>
#include "OllamaProvider.h"

class Prompt;

class ChatController {
public:
    ChatController();
    ~ChatController();
    QString processPrompt(const QString &rawPrompt);
    QString preparePromptForOllama(const QString &rawPrompt) const;

private:
    QString buildSimulatedResponse(const Prompt &prompt) const;
    bool containsKeyword(const QString &text, const QString &keyword) const;
    bool tryParseAndCreateTask(const QString &prompt, QString &outMessage);

    OllamaProvider ollamaProvider_;
};
