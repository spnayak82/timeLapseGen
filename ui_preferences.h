/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created: Sat Mar 29 11:57:53 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioBtn720p;
    QRadioButton *radioBtn1080p;
    QRadioButton *radioBtn1440p;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioBtnMP4High;
    QRadioButton *radioBtnMP4Low;
    QRadioButton *radioBtnAVI;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBoxFrameRate;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEditOutFileName;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnRender;
    QPushButton *BtnCancel;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QString::fromUtf8("Preferences"));
        Preferences->setWindowModality(Qt::WindowModal);
        Preferences->resize(672, 416);
        verticalLayout_3 = new QVBoxLayout(Preferences);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(Preferences);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(17, 25, 222, 24));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioBtn720p = new QRadioButton(widget);
        radioBtn720p->setObjectName(QString::fromUtf8("radioBtn720p"));

        horizontalLayout_3->addWidget(radioBtn720p);

        radioBtn1080p = new QRadioButton(widget);
        radioBtn1080p->setObjectName(QString::fromUtf8("radioBtn1080p"));

        horizontalLayout_3->addWidget(radioBtn1080p);

        radioBtn1440p = new QRadioButton(widget);
        radioBtn1440p->setObjectName(QString::fromUtf8("radioBtn1440p"));

        horizontalLayout_3->addWidget(radioBtn1440p);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioBtnMP4High = new QRadioButton(groupBox_3);
        radioBtnMP4High->setObjectName(QString::fromUtf8("radioBtnMP4High"));

        verticalLayout_2->addWidget(radioBtnMP4High);

        radioBtnMP4Low = new QRadioButton(groupBox_3);
        radioBtnMP4Low->setObjectName(QString::fromUtf8("radioBtnMP4Low"));

        verticalLayout_2->addWidget(radioBtnMP4Low);

        radioBtnAVI = new QRadioButton(groupBox_3);
        radioBtnAVI->setObjectName(QString::fromUtf8("radioBtnAVI"));

        verticalLayout_2->addWidget(radioBtnAVI);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout->addWidget(groupBox_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        spinBoxFrameRate = new QSpinBox(groupBox);
        spinBoxFrameRate->setObjectName(QString::fromUtf8("spinBoxFrameRate"));

        horizontalLayout_5->addWidget(spinBoxFrameRate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lineEditOutFileName = new QLineEdit(groupBox);
        lineEditOutFileName->setObjectName(QString::fromUtf8("lineEditOutFileName"));

        horizontalLayout_2->addWidget(lineEditOutFileName);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BtnRender = new QPushButton(Preferences);
        BtnRender->setObjectName(QString::fromUtf8("BtnRender"));

        horizontalLayout->addWidget(BtnRender);

        BtnCancel = new QPushButton(Preferences);
        BtnCancel->setObjectName(QString::fromUtf8("BtnCancel"));

        horizontalLayout->addWidget(BtnCancel);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Preferences);

        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Preferences", "Video Preferences", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Preferences", "Size", 0, QApplication::UnicodeUTF8));
        radioBtn720p->setText(QApplication::translate("Preferences", "720p", 0, QApplication::UnicodeUTF8));
        radioBtn1080p->setText(QApplication::translate("Preferences", "1080p", 0, QApplication::UnicodeUTF8));
        radioBtn1440p->setText(QApplication::translate("Preferences", "1440p", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Preferences", "Output Type", 0, QApplication::UnicodeUTF8));
        radioBtnMP4High->setText(QApplication::translate("Preferences", "MP4 with ljpeg codec ( produces high quality video, but takes more time to render", 0, QApplication::UnicodeUTF8));
        radioBtnMP4Low->setText(QApplication::translate("Preferences", "MP4 video with mpeg4 codec ( low quality video, takes very less time to render )", 0, QApplication::UnicodeUTF8));
        radioBtnAVI->setText(QApplication::translate("Preferences", "AVI with jpg codec ( relatively better quality video, takes less time to render )", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Preferences", "Frames per sec      ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Preferences", "Output File Name", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("Preferences", "...", 0, QApplication::UnicodeUTF8));
        BtnRender->setText(QApplication::translate("Preferences", "Start Rendering", 0, QApplication::UnicodeUTF8));
        BtnCancel->setText(QApplication::translate("Preferences", "&Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
