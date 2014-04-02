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

TimeLapseGenMain::TimeLapseGenMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TimeLapseGenMain)
{
    ui->setupUi(this);
    //filesSelected = false;

    brightness = 0;
    contrast   = 0;
    saturation = 0;

    ui->labelImage->setScaledContents(1);
    ui->labelImage->setTextFormat(Qt::RichText);
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

        qDebug() << "Using mencoder at : " << mencoderCommandPath->toAscii();

        pclose(fp);
        return true;
    }
    return false;
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

     if ( brightness == 0 && contrast == 0 && saturation == 0)
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
    //progress.setMaximum(ImageFileInfoList.size());

    for(int i=0; i< ImageFileInfoList.size(); i++){
        info = ImageFileInfoList.at(i);

        if (!needEnhancement)
            map.load(*info.getFilePath());
        else {
            data = imageEditor->enhanceImageWithoutScaling(info.getFilePath(),(brightness+100), (saturation+100), contrast );
            map.loadFromData(data,  "XPM");
        }

        destName.append(outputFilePath.toAscii());
        destName.append("/resized/");
        destName.append(info.getFileName());

        map.scaled(1920,1080, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(destName,"JPEG", 95);
        //rc = map.save(destName,"JPEG", 90);
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

    char *str = cmd.toAscii().data();
    qDebug() << "LS Path : " << str;
    fp = popen(str, "r");
    rc = pclose(fp);

    if (rc != 0 ){
        QMessageBox msg;
        msg.setWindowTitle("No Idea !");
        msg.setText("Someting went wrong while rendering timelapse... !");
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        //QMessageBox::information(this, "Error", "Someting went wrong while rendering timelapse... !", QMessageBox::Ok);
        return;
    }

    /* Execute mencoder */
    cmd.clear();

    cmd.append(mencoderCommandPath->toAscii());
    cmd.append(" -idx -nosound -noskip -ovc lavc -lavcopts ");
    if(quality == HighQualityMp4 ) {
        cmd.append(tr("vcodec=ljpeg -mf fps=%1 'mf://@files.txt' ").arg(framesPerSec));
    }
    else if ( quality == HighQualityAvi) {
        cmd.append(tr(" vcodec=msmpeg4:vbitrate=10000 -mf type-jpg:fps=%1 'mf://@files.txt' ").arg(framesPerSec));
    }
    else if ( quality == LowQualityMp4) {
        cmd.append(tr("vcodec=mpeg4 -mf fps=%1 'mf://@files.txt' ").arg(framesPerSec));
    }

    cmd.append(tr(" -o %1").arg(*outPutFileName));

    qDebug() << "CMD : " << cmd.toAscii() << endl;
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
        brightness = enhanceDialog->getBrightness();
        contrast   = enhanceDialog->getContrast();
        saturation = enhanceDialog->getSaturation();

        if ( contrast > 0 )
            contrast = contrast *1000;

        imageEditor = new editImages();
        data = imageEditor->enhanceImage(enhanceDialog->getImageFileName(), (brightness+100), (saturation+100), contrast);

        map.loadFromData(data, "XPM");

        ui->labelImage->setPixmap(map);
        //enhanceDialog->rightImage->setPixmap(map);
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
}

imageEnhanceDialog::~imageEnhanceDialog()
{
    delete enhanceDialog;
    delete imageEditor;
}

void imageEnhanceDialog::setImages(QString left, QString right)
{
    QPixmap *mapLeft, *mapRight;

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
        localContrast = mContrast * 1000;
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
        localContrast = mContrast * 1000;
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
        localContrast = mContrast * 1000;
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
    this->accept();
}
