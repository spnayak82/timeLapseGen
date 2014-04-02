#include "editImages.h"
#include <QImage>
#include <QMessageBox>
#include <QColor>
#include <QtDebug>

editImages::editImages(){

}

editImages::~editImages(){

}

QImage* editImages::addSaturation(int value, QImage *original)
{
    QImage * newImage = new QImage(original->width(), original->height(), QImage::Format_ARGB32);

    QColor oldColor;
    QColor newColor;
    int h,s,l;

    for(int x=0; x<newImage->width(); x++){
        for(int y=0; y<newImage->height(); y++){
            oldColor = QColor(original->pixel(x,y));

            newColor = oldColor.toHsl();
            h = newColor.hue();
            s = newColor.saturation()+ value;
            l = newColor.lightness();

            //oldColor.toCmyk()

            //we check if the new value is between 0 and 255
            s = qBound(0, s, 255);

            newColor.setHsl(h, s, l);

            newImage->setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));
        }
    }

    return newImage;
}

QImage* editImages::addSharpness(QImage *original)
{
    QImage * newImage = new QImage(* original);

    int kernel [3][3]= {{0,-1,0},
                          {-1,5,-1},
                          {0,-1,0}};
    int kernelSize = 3;
    int sumKernel = 1;
    int r,g,b;
    QColor color;

    for(int x=kernelSize/2; x<newImage->width()-(kernelSize/2); x++){
        for(int y=kernelSize/2; y<newImage->height()-(kernelSize/2); y++){

            r = 0;
            g = 0;
            b = 0;

            for(int i = -kernelSize/2; i<= kernelSize/2; i++){
                for(int j = -kernelSize/2; j<= kernelSize/2; j++){
                    color = QColor(original->pixel(x+i, y+j));
                    r += color.red()*kernel[kernelSize/2+i][kernelSize/2+j];
                    g += color.green()*kernel[kernelSize/2+i][kernelSize/2+j];
                    b += color.blue()*kernel[kernelSize/2+i][kernelSize/2+j];
                 }
             }

             r = qBound(0, r/sumKernel, 255);
             g = qBound(0, g/sumKernel, 255);
             b = qBound(0, b/sumKernel, 255);

             newImage->setPixel(x,y, qRgb(r,g,b));
          }
      }
      return newImage;
}

QImage* editImages::addWarmth(int value, QImage *original)
{
    QImage *newImage = new QImage(original->width(), original->height(), QImage::Format_ARGB32);

    QColor oldColor;
    int r,g,b;

    for(int x=0; x<newImage->width(); x++){
        for(int y=0; y<newImage->height(); y++){
            oldColor = QColor(original->pixel(x,y));

            r = oldColor.red() + value;
            g = oldColor.green() + value;
            b = oldColor.blue();

            //we check if the new values are between 0 and 255
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);

            newImage->setPixel(x,y, qRgb(r,g,b));
        }
    }

    return newImage;

}

QImage* editImages::changeBrightness(int value, QImage *original)
{
    QImage * newImage = new QImage(original->width(), original->height(), QImage::Format_ARGB32);

    QColor oldColor;
    int r,g,b;

    for(int x=0; x<newImage->width(); x++){
        for(int y=0; y<newImage->height(); y++){
            oldColor = QColor(original->pixel(x,y));

            /*
            r = oldColor.red() + value;
            g = oldColor.green() + value;
            b = oldColor.blue() + value;
            */
            // Contrast
            r = (( oldColor.red() - 127) * value /255 ) + 127;
            g = (( oldColor.green() - 127) * value /255 ) + 127;
            b = (( oldColor.blue() - 127) * value /255 ) + 127;

            //we check if the new values are between 0 and 255
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);
            b = qBound(0, b, 255);

            newImage->setPixel(x,y, qRgb(r,g,b));
        }
     }

     return newImage;
}

QImage* editImages::changeContrast(int value, QImage *original)
{
    QImage * newImage = new QImage(original->width(), original->height(), QImage::Format_ARGB32);

    QColor oldColor;
    int r,g,b;

    for(int x=0; x<newImage->width(); x++){
        for(int y=0; y<newImage->height(); y++){
            oldColor = QColor(original->pixel(x,y));

            // Contrast
            r = (( oldColor.red() - 127) * value /255 ) + 127;
            g = (( oldColor.green() - 127) * value /255 ) + 127;
            b = (( oldColor.blue() - 127) * value /255 ) + 127;

            //we check if the new values are between 0 and 255
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);
            b = qBound(0, b, 255);

            newImage->setPixel(x,y, qRgb(r,g,b));
        }
     }

     return newImage;
}

QImage* editImages::convertToGreyScale(QImage *original){
    QImage * newImage = new QImage(original->width(), original->height(), QImage::Format_ARGB32);

    QRgb * line;

    for(int y = 0; y<newImage->height(); y++){
        QRgb * line = (QRgb *)original->scanLine(y);

        for(int x = 0; x<newImage->width(); x++){
            int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;
            newImage->setPixel(x,y, qRgb(average, average, average));
         }
    }

    return newImage;
}

QByteArray editImages::enhanceImageWithoutScaling(QString *original, int brightness, int saturation, int contrast)
{
    Image magickImage;
    const char *fileName;
    QImage *image;
    QString oldImage(original->toAscii());
    Blob blob;
    QByteArray imgData;

    magickImage.read(original->toLocal8Bit().constData());
/*
    if ( width && height )
        magickImage.scale(Geometry(width, height));
        */

    if ( contrast )
        magickImage.contrast(contrast);

    if ( !(brightness == 100) && !(contrast == 100))
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

    if ( !(brightness == 100) && !(contrast == 100))
        magickImage.modulate(brightness, saturation, 100);

    magickImage.magick("XPM");
    magickImage.write(&blob);
    imgData = ((char*)(blob.data()));
    return imgData;
}

QImage* editImages::enhanceImage(QImage *original, int brightness, int saturation, int contrast)
{
    QImage * newImage = new QImage(original->width(), original->height(), QImage::Format_ARGB32);

    QColor oldColor;
    QColor newColor;

    int r,g,b;
    int h,s,l;

    for(int x=0; x<newImage->width(); x++){
        for(int y=0; y<newImage->height(); y++){
            oldColor = QColor(original->pixel(x,y));

            r = g = b = 0;

            if ( brightness ) {
                r = oldColor.red() + brightness;
                g = oldColor.green() + brightness;
                b = oldColor.blue() + brightness;
            }

            // Contrast
            if ( contrast ){
                r += (( oldColor.red() - 127) * contrast /255 ) + 127;
                g += (( oldColor.green() - 127) * contrast /255 ) + 127;
                b += (( oldColor.blue() - 127) * contrast /255 ) + 127;
            }

            //we check if the new values are between 0 and 255
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);
            b = qBound(0, b, 255);

            newImage->setPixel(x,y, qRgb(r,g,b));

            // Saturation
            if ( saturation ){
                oldColor = QColor(newImage->pixel(x,y));

                newColor = oldColor.toHsl();
                h = newColor.hue();
                s = newColor.saturation()+ saturation;
                l = newColor.lightness();

                //we check if the new value is between 0 and 255
                s = qBound(0, s, 255);

                newColor.setHsl(h, s, l);

                newImage->setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));
            }
        }
     }

     return newImage;
}

