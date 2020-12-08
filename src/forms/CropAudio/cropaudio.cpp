#include "cropaudio.hpp"
#include "ui_cropaudio.h"

CropFileForm::CropFileForm(
        const QString& path,
        const bool& isAudio,
        QWidget *parent) :
    QDialog(parent),
    tempPath(path),
    isAudio(isAudio),
    ui(new Ui::CropAudio)
{
    ui->setupUi(this);
}

CropFileForm::~CropFileForm()
{
    delete ui;
}

void CropFileForm::on_checkBox_fromBegin_stateChanged(int arg1)
{
    ui->timeEdit_from->setEnabled(!ui->checkBox_fromBegin->isChecked());
}

void CropFileForm::on_checkBox_tillEnd_stateChanged(int arg1)
{
    ui->timeEdit_to->setEnabled(!ui->checkBox_tillEnd->isChecked());
}

void CropFileForm::on_pushButton_saveAs_clicked()
{
    if(isAudio)
        cropAudio();
    else
        cropVideo();
}

void CropFileForm::cropAudio()
{
    auto path = QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "d:\\",
                tr("Music file (*.mp3)"));

    auto resultPath = Model::cropAudio(
                tempPath,
                ui->checkBox_fromBegin->isChecked() ?
                    NULL :
                    ui->timeEdit_from->time().toString("HH:mm:ss.zzzz"),
                ui->checkBox_tillEnd->isChecked() ?
                    NULL :
                    ui->timeEdit_to->time().toString("HH:mm:ss.zzzz"),
                path);

    if (resultPath == NULL)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("File crop");
        msgBox.setText("Error.");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("File crop");
        msgBox.setText("Success.");
        msgBox.exec();
    }
}

void CropFileForm::cropVideo()
{
    auto path = QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "d:\\",
                tr("Video file (*.mp4)"));

    auto resultPath = Model::cropVideo(
                tempPath,
                ui->checkBox_fromBegin->isChecked() ?
                    NULL :
                    ui->timeEdit_from->time().toString("HH:mm:ss.zzzz"),
                ui->checkBox_tillEnd->isChecked() ?
                    NULL :
                    ui->timeEdit_to->time().toString("HH:mm:ss.zzzz"),
                path);

    if (resultPath == NULL)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("File crop");
        msgBox.setText("Error.");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("File crop");
        msgBox.setText("Success.");
        msgBox.exec();
    }
}
