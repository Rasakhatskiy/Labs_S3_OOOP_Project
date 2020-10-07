#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "src/Executor/executor.hpp"


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


void MainWindow::on_pushButton_urlSearch_clicked()
{
    auto text = ui->lineEdit_urlSearch->text();
    auto bash = "youtube-dl " + text;
    Executor::execute(bash.toStdString().c_str());
}
