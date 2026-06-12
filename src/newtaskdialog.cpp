#include "newtaskdialog.h"
#include "ui_newtaskdialog.h"
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

    QString titulo = ui->titleEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    QDateTime fecha = ui->dueDateTimeEdit->dateTime();




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
