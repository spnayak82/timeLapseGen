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

#include "timelapsegenmain.h"
#include "ui_timelapsegenmain.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsGridLayout>
#include <QLabel>
#include <QPixmap>
#include <Magick++/Image.h>
#include <QDebug>
#include <QPixmap>
#include <QProgressDialog>

QString welcomePage = "<h3>Generate Time Lapse Videos in 3 easy steps </h3><br>" \
                        "<table width=200px border=0 cellspacing='3' cellpadding='3'>  " \
                        "<tr><td><img src=':/root/img/Camera-icon.png'/></td><td valign='middle'><p>1. Select the images ( Crtl + L ) to generate timelapse</p></td></tr>" \
                        "<tr><td><img src=':/root/img/Pixelmator-icon.png'/></td><td width=150px valign='middle'><p width=150px>2. Enhance Image according to your needs( Crtl + E ). <br>You can change brightness, contrast and saturation of the image.<br> You can also choose between 3 presets available. This is an optional step</p></td></tr>" \
                        "<tr><td><img src=':/root/img/Television-icon.png'/></td><td><p valign='middle'>3. Finally render the timelapse by selecting Video quality and Resolution( Crtl + G )</p></td></tr></table>";

TimeLapseGenMain::TimeLapseGenMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TimeLapseGenMain)
{
    ui->setupUi(this);

    brightness = 0;
    contrast   = 0;
    saturation = 0;
    eType      = None;

    ui->labelImage->setScaledContents(1);
    ui->labelImage->setTextFormat(Qt::RichText);
    ui->labelImage->setText(welcomePage);
    connect(this, SIGNAL(filesSelected()), this, SLOT(loadImagesIntoMemory()));
}

TimeLapseGenMain::~TimeLapseGenMain()
{
    delete ui;
}

void TimeLapseGenMain::on_actionSelect_Images_triggered()
{
    QFileDialog fileChooseDialog;

    fileChooseDialog.setFileMode(QFileDialog::ExistingFiles);
    fileChooseDialog.setNameFilter(tr("Images (*.png, *.jpeg, *.jpg, *JPG"));
    fileChooseDialog.setWindowTitle("Select Images");

    if ( fileChooseDialog.exec()){
        selectedFileNames = fileChooseDialog.selectedFiles();
        emit filesSelected();
    }

}

bool TimeLapseGenMain::checkMencoder()
{
    FILE *fp;
    int rc;
    char buff[128];

    fp = popen("which mencoder", "r");

    /* red the output from command */
    if ( fgets(buff, sizeof(buff), fp) != NULL) {
        // Remove the last \n
        buff[strlen(buff)-1] = '\0';
        mencoderCommandPath = new QString(buff);

        qDebug() << "Found mencoder at - " << mencoderCommandPath->toAscii();

        pclose(fp);

        fp = popen("which avconv", "r");
        if ( fgets(buff, sizeof(buff), fp) != NULL) {
            // Remove the last \n
            buff[strlen(buff)-1] = '\0';
            avconvCommandPath = new QString(buff);
            avconvPresent = true;

            qDebug() << "Found avconv at -" << avconvCommandPath->toAscii();
            pclose(fp);
        }
        else
            QMessageBox::warning(this, "Avconv not found", "avconv utility is not installed, this is required to render high quality MP4 videos", QMessageBox::Ok);

        return true;
    }

    return false;
}

bool TimeLapseGenMain::renderVideo(QString cmd)
{
    FILE *fp;
    int rc;
    char buff[1024];

    fp = popen(cmd.toAscii().constData(), "r");

    QProgressDialog progress(this);

    progress.setLabelText("Rendering Video....");
    progress.setWindowModality(Qt::WindowModal);
    progress.show();

    int i=0;
    while ( fgets(buff, sizeof(buff), fp) != NULL) {
        qDebug() << buff;
        progress.setValue(i++);
    }

    rc = pclose(fp);
    /*
    if ( rc != 0)
    {
        QMessageBox::warning(this, "Rendering Error", "Unable to render video", QMessageBox::Ok);
        return false;
    }
    */
    return true;
}

void TimeLapseGenMain::loadImagesIntoMemory()
{
    QPixmap *lapseImage;
    imageFileInfo *fileInfo;
    //QFileInfo info;

    QProgressDialog progress("Loading Images ....", QString(), 0, selectedFileNames.count(), this);

    progress.setWindowModality(Qt::WindowModal);
    progress.show();

    lapseImage = new QPixmap(selectedFileNames[0]);

    ui->labelImage->setPixmap(lapseImage->scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    for (int i=0; i < selectedFileNames.count(); i++){
        fileInfo = new imageFileInfo();

        QFileInfo info(selectedFileNames[i]);
        fileInfo->setCreatedTime(info.created());
        fileInfo->setFilePath(info.filePath());
        fileInfo->setFilename(info.fileName());

        ImageFileInfoList.append(*fileInfo);

        progress.setValue(i);
    }

    mencoderPresent = true;
    avconvPresent   = true;

    /* Check if we have required tools to generate timelapse */
    if ( !checkMencoder() )
    {
        QMessageBox msg;
        msg.setText("Unable to find mencoder tool...\nInstall it by running 'sudo apt-get install mencoder' on the terminal");
        msg.setIcon(QMessageBox::Warning);
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        //QMessageBox::info(this, "Tools Required", "Unable to find mencoder tool...\nInstall it by running 'sudo apt-get install mencoder' on the terminal", QMessageBox::Ok);
        mencoderPresent = false;
    }
}

void TimeLapseGenMain::on_actionGenerate_Timelapse_triggered()
{
    imageFileInfo info;
    QByteArray data;
    QString outputFilePath;
    QString destName;
    bool needEnhancement;
    QPixmap map;
    FILE *fp;
    int rc;
    enum VideoQuality quality;
    enum VideoResolution resolution;
    int framesPerSec ;
    QString *outPutFileName;

    if(selectedFileNames.length() == 0 )
    {
        QMessageBox msg;

        msg.setText("No Images loaded, load images first");
        msg.setWindowTitle("Rendering Error !");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(QMessageBox::Ok);
        msg.exec();

        return;
    }

    preferencesDialog = new Preferences(this);

    if (preferencesDialog->exec() == QDialog::Accepted)
    {
        quality         = preferencesDialog->getQuality();
        resolution      = preferencesDialog->getResolution();
        framesPerSec    = preferencesDialog->getFramesPerSec();
        outPutFileName  = preferencesDialog->getOutFileName();
        outPutFileName->replace(" ", "\\ ");
    }
    else
        return;

    if ( avconvPresent == false && quality == HighQualityMp4 )
    {
        QMessageBox::critical(this, "Can not render", "Rendering high quality MP4 required avconv utility, please try again with a different quality setting", QMessageBox::Ok);
        return;
    }

    /* First create a sub directory to store the images to render */
    QFileInfo infoDir(selectedFileNames[0]);

    if (!infoDir.dir().exists("resized"))
        infoDir.dir().mkdir("resized");

    /* Setup Progress Bar */
    QProgressDialog progress("Resizing Images ....", QString(), 0, selectedFileNames.count(), this);

    progress.setWindowModality(Qt::WindowModal);
    progress.show();

    outputFilePath = infoDir.path();

     if ( brightness == 0 && contrast == 0 && saturation == 0 && eType == None)
         needEnhancement = false;
     else
         needEnhancement = true;

    /* Now for each image do the following
     * 1. if brightness or contrast or saturation are specified enhance image accordingly.
     * 2. If not, directly scale the image to specified size
     * 3. Save the enhanced/resized image to destination folder i.e resized
     * 4. Update the progress bar, Since we are enhancing and resizing in the same loop,
     *    change the lable of progress bar to enhancing after 50%
     */

    for(int i=0; i< ImageFileInfoList.size(); i++){
        info = ImageFileInfoList.at(i);

        if (!needEnhancement) {
            map.load(*info.getFilePath());
            //map.scaled(1920,1080, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(destName,"JPEG", 95);
        }
        else {
            if ( eType != None)
            {
                switch(eType) {
                    case vividImage:
                        data = imageEditor->enhanceImageWithoutScaling(info.getFilePath(), 110, 200, 2000);
                        break;
                    case grayScale:
                        data = imageEditor->enhanceImageWithoutScaling(info.getFilePath(), 100, 0, 100);
                        break;
                    case autoEnhance:
                        data = imageEditor->enhanceImageWithoutScaling(info.getFilePath(), 110, 100, 1400);
                        break;
                }
            }
            else {
                data = imageEditor->enhanceImageWithoutScaling(info.getFilePath(),(brightness+100), (saturation+100), contrast );
            }

            map.loadFromData(data,  "XPM");
        }

        destName.append(outputFilePath.toAscii());
        destName.append("/resized/");
        destName.append(info.getFileName());

        if ( resolution == v720p )
            map.scaled(1280,720, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(destName,"JPEG", 95);
        else if (resolution == v1080p )
            map.scaled(1920,1080, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(destName,"JPEG", 95);
        else if (resolution == v1440p)
            map.scaled(2560,1440, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(destName,"JPEG", 95);

        progress.setValue(i);

        if ( progress.value() == (progress.maximum()/2) )
        {
            if( needEnhancement )
                progress.setLabelText("Enhacing Images....");
        }
        destName.clear();
    }

    /* Now start rendering timelapse Video */

    /* first list all the files and direct it to a file */
    QString cmd;

    cmd.append("cd ");
    cmd.append(outputFilePath.replace(" ", "\\ "));
    cmd.append("/resized; ls -1rt | grep -v files > files.txt");

    qDebug() << "LS Path : " << cmd.toAscii();
    fp = popen(cmd.toAscii().constData(), "r");
    rc = pclose(fp);

    if (rc != 0 ){
        QMessageBox msg;
        msg.setWindowTitle("No Idea !");
        msg.setText("Someting went wrong while rendering timelapse... !");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }

    /* Execute mencoder */
    cmd.clear();

    cmd.append("cd ");
    cmd.append(outputFilePath);
    cmd.append("/resized; ");
    cmd.append(mencoderCommandPath->toAscii());
    cmd.append(" -idx -nosound -noskip -ovc lavc -lavcopts ");
    if(quality == HighQualityMp4 ) {
        cmd.append(tr("vcodec=ljpeg -mf fps=%1 'mf://@files.txt' ").arg(framesPerSec));
    }
    else if ( quality == HighQualityAvi) {
        cmd.append(tr(" vcodec=msmpeg4:vbitrate=10000 -mf type=jpeg -mf fps=%1 'mf://@files.txt' ").arg(framesPerSec));
    }
    else if ( quality == LowQualityMp4) {
        cmd.append(tr("vcodec=mpeg4 -mf fps=%1 'mf://@files.txt' ").arg(framesPerSec));
    }

    if ( quality == HighQualityMp4 ) {
        cmd.append(" -o temp.avi; ");
        cmd.append("avconv -i temp.avi -c:v libx264 -preset slow -crf " );
        cmd.append(tr("%1 ").arg(framesPerSec));
        cmd.append(*outPutFileName);
    }
    else
        cmd.append(tr(" -o %1").arg(*outPutFileName));

    qDebug() << "CMD : " << cmd.toAscii() << endl;

    /* Now execute mencoder command */
    renderVideo(cmd);
}

void TimeLapseGenMain::on_action_Enhance_Images_triggered()
{
    QByteArray data;
    QPixmap map;

    if(selectedFileNames.length() == 0 )
    {
        QMessageBox msg;
        msg.setWindowTitle("Image Enhance Error !");
        msg.setText("No Images loaded, load images first");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(QMessageBox::Ok);
        msg.exec();

        //QMessageBox::information(this, "No images loaded", "Load images first", QMessageBox::Ok);
        return;
    }

    enhanceDialog = new imageEnhanceDialog(this);

    enhanceDialog->setImages(selectedFileNames[1], selectedFileNames[1]);

    if ( enhanceDialog->exec()  == QDialog::Accepted )
    {
        imageEditor = new editImages();
        if ( (eType = enhanceDialog->getAutoEnhancementType()) != None  )
        {
            switch(eType) {
                case vividImage:
                    data = imageEditor->enhanceImage(enhanceDialog->getImageFileName(), 110, 200, 2000);
                    break;
                case grayScale:
                    data = imageEditor->enhanceImage(enhanceDialog->getImageFileName(), 100, 0, 100);
                    break;
                case autoEnhance:
                    data = imageEditor->enhanceImage(enhanceDialog->getImageFileName(), 110, 100, 1400);
                    break;
            }
        }
        else {
            brightness = enhanceDialog->getBrightness();
            contrast   = enhanceDialog->getContrast();
            saturation = enhanceDialog->getSaturation();

            if ( contrast > 0 )
                contrast = contrast *1000;

            data = imageEditor->enhanceImage(enhanceDialog->getImageFileName(), (brightness+100), (saturation+100), contrast);
        }

        map.loadFromData(data, "XPM");
        ui->labelImage->setPixmap(map);
    }
}

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    preferences(new Ui::Preferences)
{
    preferences->setupUi(this);
    mFramesPerSec = 20; // default is set to 20
    mQuality = HighQualityAvi;
    mResolution = v1080p;
}

Preferences::~Preferences()
{
    delete preferences;
}

imageEnhanceDialog::imageEnhanceDialog(QWidget *parent) :
    QDialog(parent),
    enhanceDialog(new Ui::imageEnhanceDialog)
{
    enhanceDialog->setupUi(this);

    /* Set the slider to the middle */
    enhanceDialog->sliderBrightness->setMaximum(50);
    enhanceDialog->sliderBrightness->setMinimum(-50);
    enhanceDialog->sliderBrightness->setValue(0);

    enhanceDialog->sliderContrast->setMaximum(100);
    enhanceDialog->sliderContrast->setMinimum(0);
    enhanceDialog->sliderContrast->setValue(0);

    enhanceDialog->sliderSaturation->setMaximum(100);
    enhanceDialog->sliderSaturation->setMinimum(-100);
    enhanceDialog->sliderSaturation->setValue(0);

    imageEditor = new editImages();

    mBrightness = 0;
    mContrast   = 0;
    mSaturation = 0;

    eType = None;
}

imageEnhanceDialog::~imageEnhanceDialog()
{
    delete enhanceDialog;
    delete imageEditor;
}

void imageEnhanceDialog::setImages(QString left, QString right)
{
    mapLeft = new QPixmap(left);
    mapRight = new QPixmap(right);

    enhanceDialog->leftImage->setPixmap(mapLeft->scaled(400, 400,Qt::KeepAspectRatio, Qt::SmoothTransformation));
    enhanceDialog->rightImage->setPixmap(mapRight->scaled(400, 400,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    oldImage = new QImage(right);
    imageFileName = new QString(left);
}


void imageEnhanceDialog::on_sliderBrightness_valueChanged(int value)
{
    mBrightness = value;
}

void imageEnhanceDialog::on_sliderContrast_valueChanged(int value)
{
    mContrast = value;
}

void imageEnhanceDialog::on_sliderSaturation_valueChanged(int value)
{
    mSaturation = value;
}

/*
void imageEnhanceDialog::on_BtnApply_clicked()
{
    mBrightness = enhanceDialog->sliderBrightness->value();
    mContrast   = enhanceDialog->sliderContrast->value();
    mSaturation = enhanceDialog->sliderSaturation->value();
}
*/

void imageEnhanceDialog::on_pushButton_2_clicked()
{
    mBrightness = 0;
    mContrast   = 0;
    mSaturation = 0;

    this->reject();
}

void imageEnhanceDialog::on_sliderBrightness_sliderMoved(int position)
{
    enhanceDialog->labelBrightness->setText(tr("%1").arg(position));
}


void imageEnhanceDialog::on_sliderBrightness_sliderReleased()
{
    QByteArray data;
    QPixmap map;
    int localContrast;


    qDebug() << "Contrast : " << mContrast << endl;

    if ( mContrast )
        localContrast = mContrast * 500 + 500;
    else
        localContrast = 0;

    data = imageEditor->enhanceImage(imageFileName, (mBrightness+100), (mSaturation+100), localContrast);

    map.loadFromData(data, "XPM");
    enhanceDialog->rightImage->clear();
    enhanceDialog->rightImage->setPixmap(map);


    data.clear();
}

void imageEnhanceDialog::on_sliderContrast_sliderMoved(int position)
{
    enhanceDialog->labelContrast->setText(tr("%1").arg(position));
}

void imageEnhanceDialog::on_sliderSaturation_sliderMoved(int position)
{
    enhanceDialog->labelSaturation->setText(tr("%1").arg(position));
}

void imageEnhanceDialog::on_sliderContrast_sliderReleased()
{
    QByteArray data;
    QPixmap map;
    int localContrast;


    qDebug() << "Contrast : " << mContrast << endl;

    if ( mContrast )
        localContrast = mContrast * 500 + 500;
    else
        localContrast = 0;

    data = imageEditor->enhanceImage(imageFileName, (mBrightness+100), (mSaturation+100), localContrast);

    map.loadFromData(data, "XPM");
    enhanceDialog->rightImage->clear();
    enhanceDialog->rightImage->setPixmap(map);

    data.clear();
}

void imageEnhanceDialog::on_sliderSaturation_sliderReleased()
{
    QByteArray data;
    QPixmap map;
    int localContrast;

    qDebug() << "Contrast : " << mContrast << endl;

    if ( mContrast )
        localContrast = mContrast * 500 + 500;
    else
        localContrast = 0;

    data = imageEditor->enhanceImage(imageFileName, (mBrightness+100), (mSaturation+100), localContrast);

    map.loadFromData(data, "XPM");
    enhanceDialog->rightImage->clear();
    enhanceDialog->rightImage->setPixmap(map);

    data.clear();
}

void imageEnhanceDialog::on_pushButton_clicked()
{
    mBrightness = enhanceDialog->sliderBrightness->value();
    mContrast   = enhanceDialog->sliderContrast->value();
    mSaturation = enhanceDialog->sliderSaturation->value();

    this->accept();
}


void Preferences::on_BtnCancel_clicked()
{
    this->reject();
}

void Preferences::on_BtnRender_clicked()
{
    if ( preferences->radioBtnMP4High->isChecked())
        mQuality = HighQualityMp4;
    else if ( preferences->radioBtnAVI->isChecked())
        mQuality = HighQualityAvi;
    else if ( preferences->radioBtnMP4Low->isChecked())
        mQuality = LowQualityMp4;
    else {
        QMessageBox::warning(this, "Select Video Quality", "Please select a Video output Quality", QMessageBox::Ok);
        return;
    }

    if ( preferences->radioBtn1080p->isChecked())
        mResolution = v1080p;
    else if ( preferences->radioBtn1440p->isChecked())
        mResolution = v1440p;
    else if ( preferences->radioBtn720p->isChecked())
        mResolution = v720p;
    else {
        QMessageBox::warning(this, "Select Resolution", "Please select a Video resolution", QMessageBox::Ok);
    }

    if ( preferences->spinBoxFrameRate->value() == 0) {
        QMessageBox::warning(this, "Frame Rate", "Enter a Frame rate...", QMessageBox::Ok);
        return;
    }
    else
        mFramesPerSec = preferences->spinBoxFrameRate->value();

    if ( outPutFileName == NULL )
    {
        QMessageBox::warning(this, "Choose file name", "Please choose a file name to save video...", QMessageBox::Ok);
        return;
    }
    else if ( outPutFileName->isEmpty()){
        QMessageBox::warning(this, "Choose file name", "Please choose a file name to save video...", QMessageBox::Ok);
        return;
    }

    this->accept();
}

void Preferences::on_radioBtnMP4High_clicked()
{
    mQuality = HighQualityMp4;
}


void Preferences::on_radioBtnAVI_clicked()
{
    mQuality = HighQualityAvi;
}

void imageEnhanceDialog::disableSliders()
{
    enhanceDialog->sliderBrightness->setEnabled(false);
    enhanceDialog->sliderContrast->setEnabled(false);
    enhanceDialog->sliderSaturation->setEnabled(false);
}

void imageEnhanceDialog::enableSliders()
{
    enhanceDialog->sliderBrightness->setEnabled(true);
    enhanceDialog->sliderContrast->setEnabled(true);
    enhanceDialog->sliderSaturation->setEnabled(true);
}

void imageEnhanceDialog::on_radioBtnNone_clicked(bool checked)
{
    if (checked)
    {
        enhanceDialog->rightImage->setPixmap(mapRight->scaled(400, 400,Qt::KeepAspectRatio, Qt::SmoothTransformation));
        enableSliders();
        eType = None;
    }
}

void imageEnhanceDialog::on_radioBtnAutoEnhance_clicked(bool checked)
{
    QByteArray data;
    QPixmap map;

    if ( checked)
    {
        disableSliders();
        data = imageEditor->enhanceImage(imageFileName, 110, 120, 1400);

        map.loadFromData(data, "XPM");
        enhanceDialog->rightImage->clear();
        enhanceDialog->rightImage->setPixmap(map);

        eType = autoEnhance;
    }

}

void imageEnhanceDialog::on_radioBtnVivid_clicked(bool checked)
{
    QByteArray data;
    QPixmap map;

    if(checked)
    {
        disableSliders();
        data = imageEditor->enhanceImage(imageFileName, 110,200,2000);

        map.loadFromData(data, "XPM");
        enhanceDialog->rightImage->clear();
        enhanceDialog->rightImage->setPixmap(map);

        eType = vividImage;
    }

}

void imageEnhanceDialog::on_radioGrayScale_clicked(bool checked)
{
    QByteArray data;
    QPixmap map;

    if(checked)
    {
        disableSliders();

        data = imageEditor->enhanceImage(imageFileName, 100,0,100);

        map.loadFromData(data, "XPM");
        enhanceDialog->rightImage->clear();
        enhanceDialog->rightImage->setPixmap(map);

        eType = grayScale;
    }
}

void Preferences::on_pushButtonChooseFile_clicked()
{
    QString fileName("untitlted.");

    if(mQuality == HighQualityAvi )
        fileName.append("avi");
    else
        fileName.append("mp4");

    outPutFileName = new QString (QFileDialog::getSaveFileName(this, tr("Save Video in a file"),
                                fileName,
                                tr("Video files (*.mp4 *.avi)")));
    if(outPutFileName->isEmpty())
    {
        QMessageBox::warning(this, "Choose a file name", "Please choose a file to save the video...", QMessageBox::Ok);
        return;
    }

    preferences->lineEditOutFileName->setText(*outPutFileName);
}

void TimeLapseGenMain::on_action_Preferences_triggered()
{
    QMessageBox::information(this, "Feature not found", "This Feature is not yet available", QMessageBox::Ok);
}
