#ifndef MODEL_HPP
#define MODEL_HPP

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>


class Model
{
    const QString TEMP_PATH_VIDEO = "video_temp.m4a";
public:
    Model();

    /*!
     * \brief Downloads video from youtube, saves it to temp file and returns it's name.
     * \param url Youtube video url.
     * \return Path of temp file if succeeded, NULL if not.
     */
    static QString downloadVideo(const QString& url);

    /*!
     * \brief Downloads audio from youtube, saves it to temp file and returns it's name.
     * \param url Youtube video url.
     * \return Path of temp file if succeeded, NULL if not.
     */
    static QString downloadAudio(const QString& url);

    /*!
     * \brief Crops downloaded audio with given parameters and converts to mp3.
     * \param path Path of the downloaded file.
     * \param from Time code from where to cut, e.g. 01:55.3, 0, 3600, etc.
     * \param to Time code where to cut, e.g. 01:55.3, 0, 3600, etc.
     * \param resultName Desired cropped file name
     * \return Cropped file name.
     */
    static QString cropAudio(
            const QString& path,
            const QString& from,
            const QString& to,
            const QString& resultName);
};

#endif // MODEL_HPP
