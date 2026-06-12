#pragma once

#include <QString>
#include "OllamaProvider.h"

class Prompt;

class ChatController {
    public:
        ChatController();
        ~ChatController();
        // agregar funciones para enlazar el input del usuario con la respuesta del LLM
        QString processPrompt(const QString &rawPrompt);
        QString preparePromptForOllama(const QString &rawPrompt) const;
        OllamaProvider ollama; 
        static const int n = 2;
        QString modelsList[n] = {QString("gemma"), QString("qwen")};

    private:
        QString buildSimulatedResponse(const Prompt &prompt) const;
        bool containsKeyword(const QString &text, const QString &keyword) const;
};
