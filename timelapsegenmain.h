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

private:
    Ui::imageEnhanceDialog *enhanceDialog;
    editImages *imageEditor;
    int mBrightness;
    int mContrast;
    int mSaturation;
    QImage *oldImage;
    QString *imageFileName;
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
    int brightness;
    int saturation;
    int contrast;
    QList<imageFileInfo> ImageFileInfoList;
    int mBrightness, mContrast, mSaturation;
    bool mencoderPresent;

};



#endif // TIMELAPSEGENMAIN_H
