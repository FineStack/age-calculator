#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDate"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calendarWidget_selectionChanged()
{
    int year = QDate::currentDate().year() - ui->calendarWidget->selectedDate().year();
    int month = QDate::currentDate().month() - ui->calendarWidget->selectedDate().month();
    int day = QDate::currentDate().day() - ui->calendarWidget->selectedDate().day();

    if(day < 0)
    {
        day += 30;
        month--;
    }
    if (month < 0)
    {
        month += 12;
        year--;
    }

    if(year < 0)
    {
        ui->lineEdit->setText(QString("You are from the future."));
    }
    else
    {
        ui->lineEdit->setText(QString("%1 Years, %2 Months, %3 Days").arg(year).arg(month).arg(day));
    }
}
