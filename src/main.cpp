#include "forms/mainwindow.hpp"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFile styleFile("://forms/stylesheet.qss");
    styleFile.open(QFile::ReadOnly);
    a.setStyleSheet(QString::fromLatin1(styleFile.readAll()));
    styleFile.close();

    return a.exec();
}
