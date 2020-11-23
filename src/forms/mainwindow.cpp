#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QProcess>



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
    if(QFileInfo::exists(ui->lineEdit_outText->text()))
    {
        QFile file (ui->lineEdit_outText->text());
        file.remove();
    }

    QString tempName = "d:\\Temp\\temp_a.m4a";
    if(QFileInfo::exists(tempName))
    {
        QFile file (tempName);
        file.remove();
    }

    QString app = "youtube-dl";

    QStringList arguments;
    QString format = "bestaudio";
    QString path = tempName;
    QString text = ui->lineEdit_urlSearch->text();
    arguments << "-f" << format << "-o" << path << text;

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    ui->textEdit->append(app + " " + arguments.join(" "));
    process.start(app, arguments);
    process.waitForFinished();
    ui->textEdit->append(process.readAllStandardOutput());
    ui->textEdit->append(process.readAllStandardError());
    ui->textEdit->append("###############################");
    on_pushButton_Cut_clicked();
}

void MainWindow::on_pushButton_Cut_clicked()
{
    QString app = "ffmpeg";
    QStringList arguments;
    QString path ="d:\\Temp\\temp_a.m4a";
    arguments << "-ss" << ui->timeEdit_from->text()
              << "-to" << ui->timeEdit_to->text()
              << "-i"  << path
              << "-c:a" <<  "libmp3lame" << "-q:a" << "8"
              << ui->lineEdit_outText->text();

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    ui->textEdit->append(app + " " + arguments.join(" "));
    process.start(app, arguments);
    process.waitForFinished();
    ui->textEdit->append(process.readAllStandardOutput());
    ui->textEdit->append(process.readAllStandardError());
    ui->textEdit->append("###############################");
}

void MainWindow::on_pushButton_browse_clicked()
{
    ui->lineEdit_outText->setText(
                QFileDialog::getSaveFileName(
                    this,
                    tr("Save File"),
                    "d:\\",
                    tr("Music file (*.mp3)")));
}
