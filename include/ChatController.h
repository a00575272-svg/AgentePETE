#pragma once

#include <QString>

class ChatController {
public:
    QString processPrompt(const QString &prompt) const;

private:
    bool containsKeyword(const QString &text, const QString &keyword) const;
};
