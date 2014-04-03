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

#ifndef TIMELAPSEGENMAIN_H
#define TIMELAPSEGENMAIN_H

#include <QMainWindow>
#include <Magick++.h>
#include "editImages.h"
#include "ui_enhanceimage.h"
#include "ui_preferences.h"

#include "editImages.h"
#include <QList>
#include "imagefileinfo.h"

namespace Ui {
class TimeLapseGenMain;
class imageEnhanceDialog;
class Preferences;
}

enum VideoQuality {
    HighQualityMp4 = 1,
    LowQualityMp4,
    HighQualityAvi
};

enum enhanceType {
    None = 0,
    autoEnhance,
    vividImage,
    grayScale
};

enum VideoResolution {
    v720p = 1,
    v1080p,
    v1440p
};


class imageEnhanceDialog : public QDialog
{
    Q_OBJECT

public :
    explicit imageEnhanceDialog(QWidget *parent = 0);
    ~imageEnhanceDialog();
    void setImages(QString left, QString right);

    int getContrast() { return mContrast; }
    int getSaturation() { return mSaturation; }
    int getBrightness() { return mBrightness; }
    enum enhanceType getAutoEnhancementType() { return eType; }
    QString* getImageFileName() { return imageFileName; }

private slots:
    void on_sliderBrightness_valueChanged(int value);
    void on_sliderContrast_valueChanged(int value);
    void on_sliderSaturation_valueChanged(int value);

    //void on_BtnApply_clicked();
    void on_pushButton_2_clicked();
    void on_sliderBrightness_sliderMoved(int position);
    void on_sliderBrightness_sliderReleased();
    void on_sliderContrast_sliderMoved(int position);
    void on_sliderSaturation_sliderMoved(int position);
    void on_sliderContrast_sliderReleased();
    void on_sliderSaturation_sliderReleased();
    void on_pushButton_clicked();

    void on_radioBtnNone_clicked(bool checked);

    void on_radioBtnAutoEnhance_clicked(bool checked);

    void on_radioBtnVivid_clicked(bool checked);

    void on_radioGrayScale_clicked(bool checked);

private:
    Ui::imageEnhanceDialog *enhanceDialog;
    editImages *imageEditor;
    int mBrightness;
    int mContrast;
    int mSaturation;
    QImage *oldImage;
    QString *imageFileName;
    QPixmap *mapLeft, *mapRight;
    enum enhanceType eType;

    void disableSliders();
    void enableSliders();
};

class Preferences : public QDialog
{

    Q_OBJECT

public:
    explicit Preferences(QWidget *parent =0);
    ~Preferences();
    enum VideoQuality getQuality() { return mQuality; }
    enum VideoResolution getResolution() { return mResolution; }
    int getFramesPerSec() { return mFramesPerSec; }
    QString * getOutFileName() { return outPutFileName; }

private slots:
    void on_BtnCancel_clicked();
    void on_BtnRender_clicked();

    void on_toolButton_clicked();
    void on_radioBtnMP4High_clicked();
    void on_radioBtnAVI_clicked();

private :
    Ui::Preferences *preferences;
    enum VideoQuality mQuality;
    enum VideoResolution mResolution;
    int mFramesPerSec;
    QString *outPutFileName;
};

class TimeLapseGenMain : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TimeLapseGenMain(QWidget *parent = 0);
    ~TimeLapseGenMain();
    bool checkMencoder();
    bool renderVideo(QString);

signals :
    void filesSelected();

private slots:
    void on_actionSelect_Images_triggered();
    void loadImagesIntoMemory();
    void on_action_Enhance_Images_triggered();
    void on_actionGenerate_Timelapse_triggered();

private:
    Ui::TimeLapseGenMain *ui;
    imageEnhanceDialog *enhanceDialog;
    Preferences *preferencesDialog;
    editImages *imageEditor;
    QStringList selectedFileNames;
    QString *mencoderCommandPath;
    QString *avconvCommandPath;
    int brightness;
    int saturation;
    int contrast;
    enum enhanceType eType;
    QList<imageFileInfo> ImageFileInfoList;
    int mBrightness, mContrast, mSaturation;
    bool mencoderPresent;
    bool avconvPresent;
};



#endif // TIMELAPSEGENMAIN_H
