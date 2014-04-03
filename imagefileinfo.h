/*  timeLapseGen is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
