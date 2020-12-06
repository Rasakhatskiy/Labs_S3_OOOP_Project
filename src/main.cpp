#include "forms/mainwindow.hpp"
#include "forms/MainWindow/startwindow.hpp"

#include <QApplication>
#include <QFile>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    //w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();

    QFile styleFile(":/res/forms/stylesheet.qss");
    styleFile.open(QFile::ReadOnly);
    auto qstr = QString::fromLatin1(styleFile.readAll());
    a.setStyleSheet(qstr);
    styleFile.close();

    std::cout << qstr.toStdString();

    return a.exec();
}

