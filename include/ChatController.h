#pragma once

#include <QString>

class Prompt;

class ChatController {
public:
    QString processPrompt(const QString &rawPrompt) const;
    QString preparePromptForOllama(const QString &rawPrompt) const;

private:
    QString buildSimulatedResponse(const Prompt &prompt) const;
    bool containsKeyword(const QString &text, const QString &keyword) const;
};
