#include "startwindow.hpp"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_ExtractAudio_clicked()
{
    auto path = Model::downloadAudio(ui->lineEdit->text());
    if (path == NULL)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("File download");
        msgBox.setText("Unable to download audio. Check the url or try again.");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("File downloaded.");
        msgBox.exec();
    }


}
