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

#include "editImages.h"
#include <QImage>
#include <QMessageBox>
#include <QColor>
#include <QtDebug>

editImages::editImages(){

}

editImages::~editImages(){

}

QByteArray editImages::enhanceImageWithoutScaling(QString *original, int brightness, int saturation, int contrast)
{
    Image magickImage;
    Blob blob;
    QByteArray imgData;

    magickImage.read(original->toLocal8Bit().constData());

    //magickImage.scale(Geometry("1920x1080!"));
    /*
    if ( width && height )
        magickImage.scale(Geometry());
    */

    if ( contrast )
        magickImage.contrast(contrast);

    //if ( !(brightness == 100) && !(contrast == 100))
    magickImage.modulate(brightness, saturation, 100);

    magickImage.magick("XPM");
    magickImage.write(&blob);
    imgData = ((char*)(blob.data()));
    return imgData;
}

QByteArray editImages::enhanceImage(QString *original, int brightness, int saturation, int contrast)
{
    Image magickImage;
    const char *fileName;
    QImage *image;
    QString oldImage(original->toAscii());
    Blob blob;
    QByteArray imgData;

    magickImage.read(original->toLocal8Bit().constData());

    qDebug() << "File Name : " << original->toLocal8Bit().constData() << endl;
    magickImage.scale(Geometry(400, 400));

    qDebug() << "Setting Contrast to : " << contrast << endl;

    if ( contrast )
        magickImage.contrast(contrast);

    //if ( !(brightness == 100) && !(saturation == 100))
        magickImage.modulate(brightness, saturation, 100);

    magickImage.magick("XPM");
    magickImage.write(&blob);
    imgData = ((char*)(blob.data()));
    return imgData;
}

