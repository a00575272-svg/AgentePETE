#include "MainWindow.h"
#include "Message.h"
#include "Prompt.h"
#include "PeteExceptions.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ChatController()
    , stack_(new QStackedWidget(this))
    , chatPage_(new QWidget)
    , titleLabel_(new QLabel("AgentePETE"))
    , promptLabel_(new QLabel("Prompt:"))
    , modelLabel_(new QLabel("Modelo:"))
    , answerLabel_(new QLabel("Respuesta:"))
    , sendPromptButton_(new QPushButton("→"))
    , modelCombobox_(new QComboBox)
    , prompLineEdit_(new QLineEdit)
    , modelAnswer_(new QTextEdit)
    , switchButton_(new QPushButton("📅 Calendario"))
    , calendarPage_(new calendarWin)
{
    setWindowTitle("AgentePETE");
    resize(720, 480);

    QMenu *fileMenu = menuBar()->addMenu("&Archivo");
    QAction *exitAction = fileMenu->addAction("Salir");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // --- Vista chat ---
    QFont titleFont = titleLabel_->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel_->setFont(titleFont);
    titleLabel_->setAlignment(Qt::AlignCenter);

    modelCombobox_->addItem("gemma3:4b");

    QHBoxLayout *modelBox = new QHBoxLayout;
    modelBox->addWidget(modelLabel_);
    modelBox->addWidget(modelCombobox_);

    prompLineEdit_->setPlaceholderText("Escribe un comando para la IA...");

    QHBoxLayout *inputRow = new QHBoxLayout;
    inputRow->addWidget(promptLabel_);
    inputRow->addWidget(prompLineEdit_);
    inputRow->addWidget(sendPromptButton_);

    modelAnswer_->setReadOnly(true);
    modelAnswer_->append("Sistema:\nEscribe un prompt y presiona Enter o el botón.\n");

    QVBoxLayout *chatLayout = new QVBoxLayout;
    chatLayout->addWidget(titleLabel_);
    chatLayout->addLayout(modelBox);
    chatLayout->addWidget(answerLabel_);
    chatLayout->addWidget(modelAnswer_);
    chatLayout->addLayout(inputRow);
    chatLayout->addWidget(switchButton_);
    chatPage_->setLayout(chatLayout);

    // --- Stack ---
    stack_->addWidget(chatPage_);
    stack_->addWidget(calendarPage_);
    stack_->setCurrentIndex(0);
    setCentralWidget(stack_);

    // --- Connects ---
    connect(sendPromptButton_, &QPushButton::clicked, this, &MainWindow::sendPrompt);
    connect(prompLineEdit_, &QLineEdit::returnPressed, this, &MainWindow::sendPrompt);
    connect(switchButton_, &QPushButton::clicked, this, &MainWindow::switchView);
    connect(calendarPage_, &calendarWin::regresarAlChat, this, &MainWindow::switchView);
}

MainWindow::~MainWindow() {}

void MainWindow::sendPrompt()
{
    const QString inputUser = prompLineEdit_->text().trimmed();
    if (inputUser.isEmpty()) {
        QMessageBox::warning(this, "Error", "Tu prompt no puede estar vacío");
        prompLineEdit_->setFocus();
        return;
    }
    modelAnswer_->append("Tú: " + inputUser);
    try {
        modelAnswer_->append("AgentePETE: " + processPrompt(inputUser));
    } catch (const std::exception &e) {
        modelAnswer_->append(QString("[Error] ") + e.what());
    }
    prompLineEdit_->clear();
}

void MainWindow::switchView()
{
    if (stack_->currentIndex() == 0) {
        stack_->setCurrentIndex(1);
        switchButton_->setText("💬 Chat");
    } else {
        stack_->setCurrentIndex(0);
        switchButton_->setText("📅 Calendario");
    }
}
