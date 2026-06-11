#include "MainWindow.h"
#include "ChatController.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, controller_(new ChatController)
{
    titleLabel_    = new QLabel("AgentePETE");
    subtitleLabel_ = new QLabel("Tu asistente personal de organización");
    inputLine_     = new QLineEdit;
    sendButton_    = new QPushButton("Enviar");
    historyText_   = new QTextEdit;

    QFont titleFont = titleLabel_->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel_->setFont(titleFont);
    titleLabel_->setAlignment(Qt::AlignCenter);
    subtitleLabel_->setAlignment(Qt::AlignCenter);

    inputLine_->setPlaceholderText("Escribe tu tarea o solicitud aquí...");
    historyText_->setReadOnly(true);

    QHBoxLayout *inputRow = new QHBoxLayout;
    inputRow->addWidget(inputLine_);
    inputRow->addWidget(sendButton_);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(titleLabel_);
    mainLayout->addWidget(subtitleLabel_);
    mainLayout->addWidget(historyText_);
    mainLayout->addLayout(inputRow);

    QWidget *central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);

    setWindowTitle("AgentePETE");
    setMinimumSize(600, 450);

    connect(sendButton_, &QPushButton::clicked, this, &MainWindow::onSendClicked);
    connect(inputLine_, &QLineEdit::returnPressed, this, &MainWindow::onSendClicked);
}

MainWindow::~MainWindow()
{
    delete controller_;
}

void MainWindow::onSendClicked()
{
    QString text = inputLine_->text().trimmed();
    if (text.isEmpty())
        return;

    //QString response = controller_->processPrompt(text);

    historyText_->append("Tú: " + text);
    //historyText_->append("AgentePETE: " + response);
    historyText_->append("");

    inputLine_->clear();
}
