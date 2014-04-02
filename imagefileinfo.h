#ifndef IMAGEFILEINFO_H
#define IMAGEFILEINFO_H

#include <QString>
#include <QDateTime>

class imageFileInfo {

public :
    explicit imageFileInfo();
    ~imageFileInfo();
    QString* getFileName();
    QString* getFilePath();
    QDateTime* getCreatedTime();
    void setFilename(QString);
    void setFilePath(QString);
    void setCreatedTime(QDateTime);

private :
    QString *fileName;
    QString *filePath;
    QDateTime *createdTime;
    int size;
};

#endif // IMAGEFILEINFO_H
