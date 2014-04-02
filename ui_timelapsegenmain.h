/********************************************************************************
** Form generated from reading UI file 'timelapsegenmain.ui'
**
** Created: Sat Mar 29 11:57:53 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMELAPSEGENMAIN_H
#define UI_TIMELAPSEGENMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeLapseGenMain
{
public:
    QAction *actionSelect_Images;
    QAction *action_Enhance_Images;
    QAction *actionGenerate_Timelapse;
    QAction *action_Quit;
    QAction *action_Preferences;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelImage;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TimeLapseGenMain)
    {
        if (TimeLapseGenMain->objectName().isEmpty())
            TimeLapseGenMain->setObjectName(QString::fromUtf8("TimeLapseGenMain"));
        TimeLapseGenMain->resize(996, 665);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TimeLapseGenMain->sizePolicy().hasHeightForWidth());
        TimeLapseGenMain->setSizePolicy(sizePolicy);
        TimeLapseGenMain->setBaseSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/root/img/Time-Machine-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        TimeLapseGenMain->setWindowIcon(icon);
        actionSelect_Images = new QAction(TimeLapseGenMain);
        actionSelect_Images->setObjectName(QString::fromUtf8("actionSelect_Images"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/root/img/Camera-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/root/img/Camera-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSelect_Images->setIcon(icon1);
        action_Enhance_Images = new QAction(TimeLapseGenMain);
        action_Enhance_Images->setObjectName(QString::fromUtf8("action_Enhance_Images"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/root/img/Pixelmator-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/root/img/Television-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        action_Enhance_Images->setIcon(icon2);
        actionGenerate_Timelapse = new QAction(TimeLapseGenMain);
        actionGenerate_Timelapse->setObjectName(QString::fromUtf8("actionGenerate_Timelapse"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/root/img/Video-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGenerate_Timelapse->setIcon(icon3);
        action_Quit = new QAction(TimeLapseGenMain);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Preferences = new QAction(TimeLapseGenMain);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/root/img/Settings-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/root/img/Settings-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        action_Preferences->setIcon(icon4);
        centralWidget = new QWidget(TimeLapseGenMain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 976, 520));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelImage = new QLabel(scrollAreaWidgetContents);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));

        horizontalLayout_2->addWidget(labelImage);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        TimeLapseGenMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TimeLapseGenMain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 996, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        TimeLapseGenMain->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TimeLapseGenMain);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(80, 70));
        TimeLapseGenMain->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TimeLapseGenMain);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TimeLapseGenMain->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menu_File->addAction(actionSelect_Images);
        menu_File->addAction(action_Enhance_Images);
        menu_File->addAction(actionGenerate_Timelapse);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);
        menu_Edit->addAction(action_Preferences);
        mainToolBar->addAction(actionSelect_Images);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Enhance_Images);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionGenerate_Timelapse);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Preferences);

        retranslateUi(TimeLapseGenMain);

        QMetaObject::connectSlotsByName(TimeLapseGenMain);
    } // setupUi

    void retranslateUi(QMainWindow *TimeLapseGenMain)
    {
        TimeLapseGenMain->setWindowTitle(QApplication::translate("TimeLapseGenMain", "TimeLapseGen", 0, QApplication::UnicodeUTF8));
        actionSelect_Images->setText(QApplication::translate("TimeLapseGenMain", "Select  &Images", 0, QApplication::UnicodeUTF8));
        actionSelect_Images->setShortcut(QApplication::translate("TimeLapseGenMain", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        action_Enhance_Images->setText(QApplication::translate("TimeLapseGenMain", "&Enhance Images", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Enhance_Images->setToolTip(QApplication::translate("TimeLapseGenMain", "Enhance Images [ Optional ]", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Enhance_Images->setShortcut(QApplication::translate("TimeLapseGenMain", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionGenerate_Timelapse->setText(QApplication::translate("TimeLapseGenMain", "Generate &Timelapse", 0, QApplication::UnicodeUTF8));
        actionGenerate_Timelapse->setShortcut(QApplication::translate("TimeLapseGenMain", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("TimeLapseGenMain", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("TimeLapseGenMain", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("TimeLapseGenMain", "&Preferences", 0, QApplication::UnicodeUTF8));
        action_Preferences->setShortcut(QApplication::translate("TimeLapseGenMain", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        labelImage->setText(QString());
        menu_File->setTitle(QApplication::translate("TimeLapseGenMain", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("TimeLapseGenMain", "&Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TimeLapseGenMain: public Ui_TimeLapseGenMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMELAPSEGENMAIN_H
