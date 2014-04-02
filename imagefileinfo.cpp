#include "imagefileinfo.h"
#include <QDateTime>

imageFileInfo::imageFileInfo()
{

}

imageFileInfo::~imageFileInfo()
{

}

QDateTime* imageFileInfo::getCreatedTime()
{
    return createdTime;
}

QString* imageFileInfo::getFileName()
{
    return fileName;
}

QString* imageFileInfo::getFilePath()
{
    return filePath;
}

void imageFileInfo::setCreatedTime(QDateTime date)
{
    createdTime = new QDateTime(date);
}

void imageFileInfo::setFilename(QString name)
{
    fileName = new QString(name.toAscii());
}

void imageFileInfo::setFilePath(QString path)
{
    filePath = new QString(path.toAscii());
}


