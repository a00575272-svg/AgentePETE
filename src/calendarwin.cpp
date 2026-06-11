#include "calendarwin.h"
#include "ui_calendarwin.h"
#include <QMessageBox>
#include "newtaskdialog.h"
#include "dayagendadialog.h"

calendarWin::calendarWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calendarWin)
{
    ui->setupUi(this);
    currentMonth = QDate::currentDate();
    currentMonth = QDate(currentMonth.year(), currentMonth.month(), 1);
    updateCalendar();

    dayButtons = {
        ui->day1Button,
        ui->day2Button,
        ui->day3Button,
        ui->day4Button,
        ui->day5Button,
        ui->day6Button,
        ui->day7Button,

        ui->day8Button,
        ui->day9Button,
        ui->day10Button,
        ui->day11Button,
        ui->day12Button,
        ui->day13Button,
        ui->day14Button,

        ui->day15Button,
        ui->day16Button,
        ui->day17Button,
        ui->day18Button,
        ui->day19Button,
        ui->day20Button,
        ui->day21Button,

        ui->day22Button,
        ui->day23Button,
        ui->day24Button,
        ui->day25Button,
        ui->day26Button,
        ui->day27Button,
        ui->day28Button,

        ui->day29Button,
        ui->day30Button,
        ui->day31Button
    };
    for (int i = 0; i < dayButtons.size(); i++) {
        int day = i + 1;

        connect(dayButtons[i], &QPushButton::clicked, this, [this, day]() {
            QDate selectedDate(currentMonth.year(), currentMonth.month(), day);

            DayAgendaDialog agenda(selectedDate, this);
            agenda.exec();
        });
    }

}

void calendarWin::updateCalendar(){
    ui->monthLabel->setText(currentMonth.toString("MMMM yyyy"));

    int diasDelMes = currentMonth.daysInMonth();

    for (int i = 0; i < dayButtons.size(); i++) {
        int dia = i + 1;

        if (dia <= diasDelMes) {
            dayButtons[i]->setText(QString::number(dia));
            dayButtons[i]->show();
        } else {
            dayButtons[i]->hide();
        }
    }

}

void calendarWin::on_nextMonthButton_clicked(){
    currentMonth=currentMonth.addMonths(1);
    updateCalendar();
}

void calendarWin::on_previousMonthButton_clicked(){
    currentMonth=currentMonth.addMonths(-1);
    updateCalendar();
}


calendarWin::~calendarWin()
{
    delete ui;
}

void calendarWin::on_pushButton_13_clicked()
{
    QMessageBox::information(this, "Día", "Seleccionaste este día");
}


void calendarWin::on_createTaskButton_clicked()
{
    NewTaskDialog dialog(this);

    dialog.exec();
}




