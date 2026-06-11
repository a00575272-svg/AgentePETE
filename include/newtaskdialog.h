#ifndef NEWTASKDIALOG_H
#define NEWTASKDIALOG_H

#include <QDialog>

namespace Ui {
class NewTaskDialog;
}

class NewTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTaskDialog(QWidget *parent = nullptr);
    QString getTitle() const;
    QString getDescription() const;
    QDateTime getDateTime() const;
    ~NewTaskDialog();

private slots:
    void on_saveButton_clicked();

private:
    Ui::NewTaskDialog *ui;
};

#endif // NEWTASKDIALOG_H
