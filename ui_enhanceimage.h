/********************************************************************************
** Form generated from reading UI file 'enhanceimage.ui'
**
** Created: Sat Mar 29 11:57:53 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENHANCEIMAGE_H
#define UI_ENHANCEIMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_imageEnhanceDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *leftImage;
    QLabel *rightImage;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSlider *sliderBrightness;
    QLabel *labelBrightness;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSlider *sliderContrast;
    QLabel *labelContrast;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QSlider *sliderSaturation;
    QLabel *labelSaturation;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *imageEnhanceDialog)
    {
        if (imageEnhanceDialog->objectName().isEmpty())
            imageEnhanceDialog->setObjectName(QString::fromUtf8("imageEnhanceDialog"));
        imageEnhanceDialog->resize(800, 511);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/img/Pixelmator-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        imageEnhanceDialog->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(imageEnhanceDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(imageEnhanceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	border: 1px black;\n"
"}"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Sans Serif\";"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        leftImage = new QLabel(groupBox);
        leftImage->setObjectName(QString::fromUtf8("leftImage"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftImage->sizePolicy().hasHeightForWidth());
        leftImage->setSizePolicy(sizePolicy);
        leftImage->setPixmap(QPixmap(QString::fromUtf8(":/root/img/Television-icon.png")));

        horizontalLayout_2->addWidget(leftImage);

        rightImage = new QLabel(groupBox);
        rightImage->setObjectName(QString::fromUtf8("rightImage"));
        sizePolicy.setHeightForWidth(rightImage->sizePolicy().hasHeightForWidth());
        rightImage->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(rightImage);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(imageEnhanceDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        sliderBrightness = new QSlider(groupBox_2);
        sliderBrightness->setObjectName(QString::fromUtf8("sliderBrightness"));
        sliderBrightness->setValue(0);
        sliderBrightness->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderBrightness);

        labelBrightness = new QLabel(groupBox_2);
        labelBrightness->setObjectName(QString::fromUtf8("labelBrightness"));

        horizontalLayout_3->addWidget(labelBrightness);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        sliderContrast = new QSlider(groupBox_2);
        sliderContrast->setObjectName(QString::fromUtf8("sliderContrast"));
        sliderContrast->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderContrast);

        labelContrast = new QLabel(groupBox_2);
        labelContrast->setObjectName(QString::fromUtf8("labelContrast"));

        horizontalLayout_4->addWidget(labelContrast);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        sliderSaturation = new QSlider(groupBox_2);
        sliderSaturation->setObjectName(QString::fromUtf8("sliderSaturation"));
        sliderSaturation->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sliderSaturation);

        labelSaturation = new QLabel(groupBox_2);
        labelSaturation->setObjectName(QString::fromUtf8("labelSaturation"));

        horizontalLayout_5->addWidget(labelSaturation);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(imageEnhanceDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(imageEnhanceDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(imageEnhanceDialog);

        QMetaObject::connectSlotsByName(imageEnhanceDialog);
    } // setupUi

    void retranslateUi(QDialog *imageEnhanceDialog)
    {
        imageEnhanceDialog->setWindowTitle(QApplication::translate("imageEnhanceDialog", "Enhance The Image", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("imageEnhanceDialog", "Before                                                                      After", 0, QApplication::UnicodeUTF8));
        leftImage->setText(QString());
        rightImage->setText(QString());
        groupBox_2->setTitle(QApplication::translate("imageEnhanceDialog", "Enhancements", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("imageEnhanceDialog", "Brightness :  ", 0, QApplication::UnicodeUTF8));
        labelBrightness->setText(QApplication::translate("imageEnhanceDialog", "+ 0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("imageEnhanceDialog", "Contrast :      ", 0, QApplication::UnicodeUTF8));
        labelContrast->setText(QApplication::translate("imageEnhanceDialog", "+ 0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("imageEnhanceDialog", "Saturation  : ", 0, QApplication::UnicodeUTF8));
        labelSaturation->setText(QApplication::translate("imageEnhanceDialog", "+ 0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("imageEnhanceDialog", "&Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("imageEnhanceDialog", "&Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imageEnhanceDialog: public Ui_imageEnhanceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENHANCEIMAGE_H
