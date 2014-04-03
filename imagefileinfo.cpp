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


