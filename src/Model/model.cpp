#include "model.hpp"

Model::Model()
{



}

QString Model::downloadVideo(const QString& url)
{
    return NULL;
}

QString Model::downloadAudio(const QString& url)
{
    const QString APP_NAME = "youtube-dl";
    const QString FORMAT_AUDIO = "bestaudio";
    const QString TEMP_PATH_AUDIO = "audio_temp.m4a";

    if (QFileInfo::exists(TEMP_PATH_AUDIO))
        QFile::remove(TEMP_PATH_AUDIO);

    QStringList arguments;
    arguments
            << "-f"
            << FORMAT_AUDIO
            << "-o"
            << TEMP_PATH_AUDIO
            << url;

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    auto resultFilePath = QCoreApplication::applicationDirPath() + "\\" +TEMP_PATH_AUDIO;

    qDebug() << APP_NAME + " " + arguments.join(" ");

    process.start(APP_NAME, arguments);
    process.waitForFinished();

    if (!QFileInfo::exists(resultFilePath))
    {
        return NULL;
    }
    else
    {
        QFileInfo fileInfo(resultFilePath);
        if (fileInfo.size() == 0)
            return NULL;
        else
            return resultFilePath;
    }
}

QString Model::cropAudio(const QString &path, const QString &from, const QString &to, const QString &resultName)
{
    const QString APP_NAME = "youtube-dl";
    const QString CODEC_INFO = "-c:a libmp3lame -q:a 8";
    //<< "-c:a" <<  "libmp3lame" << "-q:a" << "8"

    QStringList arguments;
    arguments
            << "-ss"
            << from
            << "-to"
            << to
            << "-i"
            << path
            << CODEC_INFO
            << resultName;

    if (QFileInfo::exists(path))
        QFile::remove(path);

    if (!QFileInfo::exists(resultName))
    {
        return NULL;
    }
    else
    {
        QFileInfo fileInfo(resultName);
        if (fileInfo.size() == 0)
            return NULL;
        else
            return resultName;
    }
}
