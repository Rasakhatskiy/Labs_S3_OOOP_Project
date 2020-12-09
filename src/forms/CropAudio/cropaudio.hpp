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

/*!
 * \brief The CropFileForm class made for selecting time range and cropping video and audio files.
 */
class CropFileForm : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief CropFileForm
     * \param[in] path Path of the temp file for cropping.
     * \param[in] isAudio Is it audio or video.
     * \param parent
     */
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

    /*!
     * \brief Reads time codes from form and launches model for cropping audio.
     */
    void cropAudio();

    /*!
     * \brief Reads time codes from form and launches model for cropping video.
     */
    void cropVideo();

    /*!
     * \brief path of the temp file for crop.
     */
    QString tempPath;

    /*!
     * \brief is this file audio or video.
     */
    bool isAudio;

    /*!
     * \brief form
     */
    Ui::CropAudio *ui;
};

#endif // CROPAUDIO_HPP
