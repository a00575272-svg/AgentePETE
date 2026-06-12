#include "newtaskdialog.h"
#include "ui_newtaskdialog.h"
#include "Task.h"
#include <filesystem>
#include "dayagendadialog.h"
#include <QMessageBox>
#include <QDateTime>
#include "calendarwin.h"


NewTaskDialog::NewTaskDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewTaskDialog)
{
    ui->setupUi(this);
}

NewTaskDialog::~NewTaskDialog()
{
    delete ui;
}

void NewTaskDialog::on_saveButton_clicked()
{
    QString titulo = ui->titleEdit->text().trimmed();
    QString description = ui->descriptionEdit->toPlainText().trimmed();
    QDateTime fecha = ui->dueDateTimeEdit->dateTime();

    if (titulo.isEmpty()) {
        QMessageBox::warning(this, "Error", "El título no puede estar vacío");
        return;
    }

    std::filesystem::create_directories("taskDir");

    Task tarea(
        fecha.date().day(),
        fecha.date().month(),
        fecha.date().year(),
        titulo.toStdString(),
        description.toStdString()
    );

    accept();
}

QString NewTaskDialog::getTitle() const
{
    return ui->titleEdit->text();
}

QString NewTaskDialog::getDescription() const
{
    return ui->descriptionEdit->toPlainText();
}

QDateTime NewTaskDialog::getDateTime() const
{
    return ui->dueDateTimeEdit->dateTime();
}
