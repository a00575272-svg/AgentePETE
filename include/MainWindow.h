#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class ChatController;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onSendClicked();

private:
    QLabel      *titleLabel_;
    QLabel      *subtitleLabel_;
    QLineEdit   *inputLine_;
    QPushButton *sendButton_;
    QTextEdit   *historyText_;

    ChatController *controller_;
};
