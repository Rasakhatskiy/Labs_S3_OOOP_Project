#ifndef STARTWINDOW_HPP
#define STARTWINDOW_HPP

#include <QDialog>
#include <QMessageBox>

#include "src/forms/CropAudio/cropaudio.hpp"
#include "src/Model/model.hpp"

namespace Ui {
class StartWindow;
}

/*!
 * \brief The StartWindow class for window where you can type youtube link and select what to extract - video or audio.
 */
class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_pushButton_ExtractAudio_clicked();

    void on_pushButton_ExtractVideo_clicked();

private:

    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_HPP
