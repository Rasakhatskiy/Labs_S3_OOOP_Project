#include "model.hpp"

Model::Model()
{



}

void Model::executeProcess(
        QProcess& process,
        const QString &app,
        const QStringList &arguments)
{
    qDebug() << app + " " + arguments.join(" ");
    process.start(app, arguments);
    process.waitForFinished(-1);
}

void Model::removeFileIfExists(
        const QString &path,
        const bool& isRelative = true)
{
    auto absolute = isRelative ?
        QCoreApplication::applicationDirPath() + "\\" + path :
        path;
    if (QFileInfo::exists(absolute))
        QFile::remove(absolute);
}

QTime Model::getFileDuration(const QString &path)
{
    //ffprobe -v error -show_entries format=duration -sexagesimal -of default=noprint_wrappers=1:nokey=1 audio_temp.m4a
    const QString APP_NAME = "ffprobe";
    QStringList arguments
    {
        "-v", "error", "-show_entries",
        "format=duration", "-sexagesimal",
        "-of", "default=noprint_wrappers=1:nokey=1",
        path
    };

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    auto result = process.readAllStandardOutput();

    try
    {
        QTime time = QTime::fromString(result, "HH:mm:ss.zzzzzz");
        return time;
    }
    catch (...)
    {
    }
    return QTime();
}

bool Model::fileExists(const QString &path)
{
    if (!QFileInfo::exists(path))
    {
        return false;
    }
    else
    {
        QFileInfo fileInfo(path);
        if (fileInfo.size() == 0)
            return false;
        else
            return true;
    }
}

QString Model::downloadVideo(const QString& url)
{
    const QString APP_NAME_YOUTUBE = "youtube-dl";
    const QString APP_NAME_FFMPEG = "ffmpeg";

    const QString FORMAT_AUDIO = "bestaudio";
    const QString FORMAT_VIDEO = "bestvideo";

    const QString TEMP_PATH_AUDIO = "video_temp_a.m4a";
    const QString TEMP_PATH_VIDEO = "video_temp_v.mp4";

    const QString TEMP_PATH_COMBINED = "video_temp_combined.mp4";

    removeFileIfExists(TEMP_PATH_AUDIO);
    removeFileIfExists(TEMP_PATH_VIDEO);
    removeFileIfExists(TEMP_PATH_COMBINED);

    QProcess process;
    auto workingDir = QCoreApplication::applicationDirPath();
    process.setWorkingDirectory(workingDir);

    QStringList arguments_1
    {
        "-f", FORMAT_AUDIO,
        "-o", TEMP_PATH_AUDIO,
        url
    };
    executeProcess(process, APP_NAME_YOUTUBE, arguments_1);
    auto resultFilePathTA = QCoreApplication::applicationDirPath() + "\\" + TEMP_PATH_AUDIO;
    if (!fileExists(resultFilePathTA)) return NULL;



    QStringList arguments_2
    {
        "-f", FORMAT_VIDEO,
        "-o", TEMP_PATH_VIDEO,
        url
    };
    executeProcess(process, APP_NAME_YOUTUBE, arguments_2);
    auto resultFilePathTV = QCoreApplication::applicationDirPath() + "\\" + TEMP_PATH_VIDEO;
    if (!fileExists(resultFilePathTV)) return NULL;



    //ffmpeg -i video.mp4 -i audio.m4a -acodec copy -vcodec copy output.mp4
    QStringList arguments_3
    {
        "-i", TEMP_PATH_VIDEO,
        "-i", TEMP_PATH_AUDIO,
        "-acodec", "copy", "-vcodec", "copy",
        TEMP_PATH_COMBINED
    };
    executeProcess(process, APP_NAME_FFMPEG, arguments_3);


    auto resultFilePathTC = QCoreApplication::applicationDirPath() + "\\" + TEMP_PATH_COMBINED;
    if (!fileExists(resultFilePathTC)) return NULL;


    removeFileIfExists(resultFilePathTA);
    removeFileIfExists(resultFilePathTV);

    return resultFilePathTC;
}

QString Model::downloadAudio(const QString& url)
{
    const QString APP_NAME = "youtube-dl";
    const QString FORMAT_AUDIO = "bestaudio";
    const QString TEMP_PATH_AUDIO = "audio_temp.m4a";

    removeFileIfExists(TEMP_PATH_AUDIO);

    QStringList arguments
    {
        "-f", FORMAT_AUDIO,
        "-o", TEMP_PATH_AUDIO,
        url
    };

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    auto resultFilePath = QCoreApplication::applicationDirPath() + "\\" +TEMP_PATH_AUDIO;
    executeProcess(process, APP_NAME, arguments);
    return fileExists(resultFilePath) ? resultFilePath : NULL;
}

QString Model::cropAudio(
        const QString &path,
        const QString &from,
        const QString &to,
        const QString &resultName)
{
    const QString APP_NAME = "ffmpeg";

    removeFileIfExists(resultName, false);
    auto info = QFileInfo(path);
    auto name = info.fileName();

    QStringList arguments;
    arguments << "-ss" << (from == NULL ? "0" : from);
    if (to != NULL) arguments << "-to" << to;
    arguments.append({
        "-i", name,
        "-c:a", "libmp3lame", "-q:a", "8",
        resultName
    });

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());

    auto resultFilePath = QCoreApplication::applicationDirPath() + "\\" + resultName;
    executeProcess(process, APP_NAME, arguments);

    return fileExists(resultName) ? resultName : NULL;
}

QString Model::cropVideo(const QString &path, const QString &from, const QString &to, const QString &resultName)
{
    const QString APP_NAME = "ffmpeg";

    removeFileIfExists(resultName, false);
    auto info = QFileInfo(path);
    auto name = info.fileName();

    QStringList arguments;
    arguments << "-ss" << (from == NULL ? "0" : from);
    if (to != NULL) arguments << "-to" << to;
    arguments.append({
        "-i", name,
        resultName
    });

    QProcess process;
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());

    auto resultFilePath = QCoreApplication::applicationDirPath() + "\\" + resultName;
    executeProcess(process, APP_NAME, arguments);

    return fileExists(resultName) ? resultName : NULL;
}
