#ifndef DAYAGENDADIALOG_H
#define DAYAGENDADIALOG_H
#include <QDate>
#include <QDialog>

namespace Ui {
class DayAgendaDialog;
}

class DayAgendaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DayAgendaDialog(const QDate &date, QWidget *parent = nullptr);
    ~DayAgendaDialog();
    void addTaskCard(const QString &title,
                     const QString &time,
                     const QString &description);

private slots:
    void on_createTaskButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::DayAgendaDialog *ui;

};



#endif // DAYAGENDADIALOG_H
