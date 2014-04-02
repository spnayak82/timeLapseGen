#ifndef EDITIMAGES_H
#define EDITIMAGES_H

#include <QImage>
#include <Magick++.h>
#include <Magick++/Image.h>

using namespace Magick;

class editImages {

public :
    explicit editImages();
    ~editImages();

    QImage* convertToGreyScale(QImage * original);
    QImage* changeBrightness(int value, QImage *original);
    QImage* changeContrast(int value, QImage *original);
    QImage* addWarmth(int value, QImage *original);
    QImage* addSaturation(int, QImage *original);
    QImage* addSharpness(QImage *original);

    QImage* enhanceImage(QImage *original, int brightness, int saturation, int contrast);
    QByteArray enhanceImage(QString *original, int brightness, int saturation, int contrast);
    /* Enhance imag with custom scaling */
    QByteArray enhanceImageWithoutScaling(QString *original, int brightness, int saturation, int contrast);
};

#endif // EDITIMAGES_H
