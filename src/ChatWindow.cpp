#include <QVBoxLayout>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <QMenu>
#include <QMenuBar>
#include "ChatWindow.h"

ChatWindow::ChatWindow(QWidget *parent)
    : QMainWindow(parent)
    , ChatController()
    , titleLabel(new QLabel("AgentePETE", this))
    , promptLabel(new QLabel("Prompt:", this))
    , modelLabel(new QLabel("Modelo:", this))
    , answerLabel(new QLabel("Respuesta:", this))
    , sendPromptButton(new QPushButton("→", this))
    , calendarButton(new QPushButton("Calendario", this))
    , modelCombobox(new QComboBox(this))
    , prompLineEdit(new QLineEdit(this))
    , modelAnswer(new QTextEdit(this))
{
    setWindowTitle("AgentePETE");
    resize(720, 480);

    QMenu *fileMenu = menuBar()->addMenu("&Archivo");
    QAction *exitAction = fileMenu->addAction("Salir");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    connect(sendPromptButton, &QPushButton::clicked, this, &ChatWindow::sendPrompt);
    connect(prompLineEdit, &QLineEdit::returnPressed, this, &ChatWindow::sendPrompt);
    connect(calendarButton, &QPushButton::clicked, this, [this]() {
        calendarWin *cal = new calendarWin(this);
        cal->show();
    });

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(titleLabel);

    QHBoxLayout *modelBox = new QHBoxLayout;
    modelBox->addWidget(modelLabel);
    modelCombobox->addItem("gemma3:4b");
    modelBox->addWidget(modelCombobox);
    vbox->addLayout(modelBox);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(promptLabel);
    prompLineEdit->setPlaceholderText("Escribe un comando para la IA...");
    hbox->addWidget(prompLineEdit);
    hbox->addWidget(sendPromptButton);
    vbox->addLayout(hbox);

    vbox->addWidget(answerLabel);
    modelAnswer->setReadOnly(true);
    modelAnswer->append("Sistema:\nEscribe un prompt y presiona \"Enter\" o el botón.\n");
    vbox->addWidget(modelAnswer);

    vbox->addWidget(calendarButton);
    central->setLayout(vbox);
}

ChatWindow::~ChatWindow() {}

void ChatWindow::sendPrompt()
{
    QString inputUser = prompLineEdit->text().trimmed();
    if (inputUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Tu prompt no puede estar vacío");
        prompLineEdit->setFocus();
        return;
    }
    modelAnswer->append("Tú: " + inputUser);
    modelAnswer->append("AgentePETE: " + processPrompt(inputUser));
    prompLineEdit->clear();
}
