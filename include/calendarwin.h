#ifndef CALENDARWIN_H
#define CALENDARWIN_H
#include <QDate>
#include <QVector>
#include <QPushButton>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class calendarWin;
}
QT_END_NAMESPACE

class calendarWin : public QMainWindow
{
    Q_OBJECT


public:
    explicit calendarWin(QWidget *parent = nullptr);
    ~calendarWin() override;

private slots:
    void on_pushButton_13_clicked();

    void on_createTaskButton_clicked();

    void on_nextMonthButton_clicked();

    void on_previousMonthButton_clicked();



private:
    Ui::calendarWin *ui;
    QDate currentMonth;
    void updateCalendar();
    QVector<QPushButton*> dayButtons;
};
#endif // CALENDARWIN_H
