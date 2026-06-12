#pragma once

#include <QString>

class Prompt;

class ChatController {
    public:
        ChatController();
        ~ChatController();
        // agregar funciones para enlazar el input del usuario con la respuesta del LLM
        QString processPrompt(const QString &rawPrompt) const;
        QString preparePromptForOllama(const QString &rawPrompt) const;

    private:
        QString buildSimulatedResponse(const Prompt &prompt) const;
        bool containsKeyword(const QString &text, const QString &keyword) const;
};
