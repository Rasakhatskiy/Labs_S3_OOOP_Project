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
};

#endif // MODEL_HPP
