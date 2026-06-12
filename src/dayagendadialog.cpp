#include "dayagendadialog.h"
#include "ui_dayagendadialog.h"
#include "Task.h"
#include <filesystem>
#include <QVBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QLabel>
#include "newtaskdialog.h"
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

DayAgendaDialog::DayAgendaDialog(const QDate &date, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DayAgendaDialog)
{
    ui->setupUi(this);
    QVBoxLayout *taskLayout = new QVBoxLayout(ui->taskScrollArea->widget());
    Q_UNUSED(taskLayout);

    ui->dateLabel->setText(date.toString("dd/MM/yyyy"));

    // Crear directorio de tareas si no existe
    std::filesystem::create_directories("taskDir");

    // Cargar tareas del día seleccionado
    std::vector<Task> tareas = Task::loadAllEntries();
    for (const Task &tarea : tareas) {
        if (tarea.getDay()   == date.day()   &&
            tarea.getMonth() == date.month() &&
            tarea.getYear()  == date.year())
        {
            addTaskCard(
                QString::fromStdString(tarea.getTitleTask()),
                "",
                QString::fromStdString(tarea.getDescriptionTask())
            );
        }
    }
}

void DayAgendaDialog::addTaskCard(const QString &title,
                                  const QString &time,
                                  const QString &description)
{
    QFrame *card = new QFrame;
    card->setMaximumHeight(160);
    card->setFrameShape(QFrame::StyledPanel);
    card->setObjectName("taskCard");

    card->setStyleSheet(
        "#taskCard {"
        "border: 1px solid gray;"
        "border-radius: 8px;"
        "padding: 8px;"
        "}"
        );

    QVBoxLayout *cardLayout = new QVBoxLayout(card);

    QLabel *titleLabel = new QLabel(title);
    QLabel *timeLabel = new QLabel(time);
    QLabel *descriptionLabel = new QLabel(description);

    QPushButton *deleteButton = new QPushButton("Eliminar");

    cardLayout->addWidget(titleLabel);
    cardLayout->addWidget(timeLabel);
    cardLayout->addWidget(descriptionLabel);
    cardLayout->addWidget(deleteButton);

    QVBoxLayout *taskLayout =
        qobject_cast<QVBoxLayout*>(ui->taskScrollArea->widget()->layout());

    taskLayout->insertWidget(taskLayout->count() - 1, card);

    connect(deleteButton, &QPushButton::clicked, this, [card]() {
        card->deleteLater();
    });
}

DayAgendaDialog::~DayAgendaDialog()
{
    delete ui;
}

void DayAgendaDialog::on_createTaskButton_clicked()
{
    NewTaskDialog dialog(this);


    if(dialog.exec() == QDialog::Accepted)
    {
        addTaskCard(
            dialog.getTitle(),
            dialog.getDateTime().time().toString("HH:mm"),
            dialog.getDescription()
            );
    }
}


void DayAgendaDialog::on_closeButton_clicked()
{
    close();
}

