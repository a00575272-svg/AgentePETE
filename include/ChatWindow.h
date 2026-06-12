#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include "ChatController.h"
#include "calendarwin.h"

class ChatWindow : public QMainWindow, public ChatController {
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow() override;

private slots:
    void sendPrompt();

private:
    QLabel      *titleLabel;
    QLabel      *promptLabel;
    QLabel      *modelLabel;
    QLabel      *answerLabel;
    QPushButton *sendPromptButton;
    QPushButton *calendarButton;
    QComboBox   *modelCombobox;
    QLineEdit   *prompLineEdit;
    QTextEdit   *modelAnswer;
};
