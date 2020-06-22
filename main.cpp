#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(QSize(428, 428));
    w.setWindowIcon(QIcon(":/icons/boy.png"));
    w.setWindowTitle("Age Calculator");
    w.show();
    return a.exec();
}
