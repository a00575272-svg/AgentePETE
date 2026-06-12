#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QComboBox>
#include "ChatController.h"
#include "calendarwin.h"

class MainWindow : public QMainWindow, public ChatController {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void sendPrompt();
    void switchView();

private:
    QStackedWidget *stack_;

    // Vista chat
    QWidget     *chatPage_;
    QLabel      *titleLabel_;
    QLabel      *promptLabel_;
    QLabel      *modelLabel_;
    QLabel      *answerLabel_;
    QPushButton *sendPromptButton_;
    QComboBox   *modelCombobox_;
    QLineEdit   *prompLineEdit_;
    QTextEdit   *modelAnswer_;

    // Navegación
    QPushButton *switchButton_;

    // Vista calendario
    calendarWin *calendarPage_;
};
