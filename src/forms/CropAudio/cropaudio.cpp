#include "cropaudio.hpp"
#include "ui_cropaudio.h"

CropAudio::CropAudio(
        const QString& path,
        QWidget *parent) :
    QDialog(parent),
    tempPath(path),
    ui(new Ui::CropAudio)
{
    ui->setupUi(this);
}

CropAudio::~CropAudio()
{
    delete ui;
}

void CropAudio::on_checkBox_fromBegin_stateChanged(int arg1)
{
    ui->timeEdit_from->setEnabled(ui->checkBox_fromBegin->isChecked());
}

void CropAudio::on_checkBox_tillEnd_stateChanged(int arg1)
{
    ui->timeEdit_to->setEnabled(ui->checkBox_tillEnd->isChecked());
}
