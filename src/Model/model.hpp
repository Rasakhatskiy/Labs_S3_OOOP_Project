#ifndef MODEL_HPP
#define MODEL_HPP

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>
#include <QTime>
#include <QDateTime>

/*!
 * \brief The Model class made for viadeo and audio files operations.
 * Uses ffmeg and youtube-dl library
 */
class Model
{
    const QString TEMP_PATH_VIDEO = "video_temp.m4a";
public:
    Model();

    /*!
     * \brief Executes external process and waits for it to finish.
     * \param process Process
     * \param app Application name
     * \param arguments Arguments
     */
    static void executeProcess(
            QProcess& process,
            const QString& app,
            const QStringList& arguments);

    /*!
     * \brief Deletes file if it exists.
     * \param Path of the file
     * \param isRelative is this path relative or absolute
     */
    static void removeFileIfExists(
            const QString &path,
            const bool& isRelative);

    /*!
     * \brief returns video duration from ffmpeg
     * \param path Path of the file
     * \return
     */
    static QTime getFileDuration(const QString &path);

    /*!
     * \brief Checks if file exists and it's size != 0
     * \param[in] path File path
     * \return True if exists and length != 0 else false
     */
    static bool fileExists(const QString& path);

    /*!
     * \brief Downloads video from youtube, saves it to temp file and returns it's name.
     * \param[in] url Youtube video url.
     * \return Path of temp file if succeeded, NULL if not.
     */
    static QString downloadVideo(const QString& url);

    /*!
     * \brief Downloads audio from youtube, saves it to temp file and returns it's name.
     * \param[in] url Youtube video url.
     * \return Path of temp file if succeeded, NULL if not.
     */
    static QString downloadAudio(const QString& url);

    /*!
     * \brief Crops downloaded audio with given parameters and converts to mp3.
     * \param[in] path Path of the downloaded file.
     * \param[in] from Time code from where to cut, e.g. 01:55.3, 0, 3600, etc.
     * \param[in] to Time code where to cut, e.g. 01:55.3, 0, 3600, etc.
     * \param[in] resultName Desired cropped file name
     * \return Cropped file name.
     */
    static QString cropAudio(
            const QString& path,
            const QString& from,
            const QString& to,
            const QString& resultName);

    /*!
     * \brief Crops downloaded video with given parameters and converts to mp3.
     * \param[in] path Path of the downloaded file.
     * \param[in] from Time code from where to cut, e.g. 01:55.3, 0, 3600, etc.
     * \param[in] to Time code where to cut, e.g. 01:55.3, 0, 3600, etc.
     * \param[in] resultName Desired cropped file name
     * \return Cropped file name.
     */
    static QString cropVideo(
            const QString& path,
            const QString& from,
            const QString& to,
            const QString& resultName);
};

#endif // MODEL_HPP
