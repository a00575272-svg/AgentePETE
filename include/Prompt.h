#pragma once

#include <QString>

class Prompt {
public:
    Prompt();
    explicit Prompt(const QString &rawText);

    bool setText(const QString &rawText);

    QString text() const;
    QString ollamaPrompt() const;
    bool isValid() const;
    QString validationError() const;

    static int maxLength();
    static QString normalize(const QString &rawText);
    static QString systemInstruction();

private:
    QString text_;
    QString validationError_;
};
