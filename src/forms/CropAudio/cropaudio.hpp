#ifndef CROPAUDIO_HPP
#define CROPAUDIO_HPP

#include <QDialog>
#include <QString>

namespace Ui {
class CropAudio;
}

class CropAudio : public QDialog
{
    Q_OBJECT

public:
    explicit CropAudio(
            const QString& path,
            QWidget *parent = nullptr);
    ~CropAudio();

private slots:
    void on_checkBox_fromBegin_stateChanged(int arg1);

    void on_checkBox_tillEnd_stateChanged(int arg1);

private:
    QString tempPath;
    Ui::CropAudio *ui;
};

#endif // CROPAUDIO_HPP
