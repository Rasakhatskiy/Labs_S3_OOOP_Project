#ifndef CROPAUDIO_HPP
#define CROPAUDIO_HPP



#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>

#include "src/Model/model.hpp"


namespace Ui {
class CropAudio;
}

class CropFileForm : public QDialog
{
    Q_OBJECT

public:
    explicit CropFileForm(
            const QString& path,
            const bool& isAudio,
            QWidget *parent = nullptr);
    ~CropFileForm();

private slots:
    void on_checkBox_fromBegin_stateChanged(int arg1);

    void on_checkBox_tillEnd_stateChanged(int arg1);

    void on_pushButton_saveAs_clicked();

private:

    void cropAudio();
    void cropVideo();

    QString tempPath;
    bool isAudio;
    Ui::CropAudio *ui;
};

#endif // CROPAUDIO_HPP
