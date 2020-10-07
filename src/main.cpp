#include "forms/mainwindow.hpp"

#include <QApplication>
#include <QFile>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
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
/*
 * #include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
 *
 */
