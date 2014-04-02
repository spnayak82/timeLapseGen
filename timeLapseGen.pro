#-------------------------------------------------
#
# Project created by QtCreator 2014-03-18T14:00:06
#
#-------------------------------------------------

QT       += core gui

TARGET = timeLapseGen
TEMPLATE = app


SOURCES += main.cpp\
        timelapsegenmain.cpp \
    editImages.cpp \
    imagefileinfo.cpp

HEADERS  += timelapsegenmain.h \
    editImages.h \
    imagefileinfo.h

FORMS    += timelapsegenmain.ui \
    enhanceimage.ui \
    preferences.ui

RESOURCES += \
    images.qrc


#INCLUDEPATH += $$PWD/
#INCLUDEPATH += $$PWD/./Magick++/
DEPENDPATH += $$PWD/

INCLUDEPATH += /usr/include/GraphicsMagick/

OTHER_FILES +=

unix:!macx:!symbian: LIBS += -lGraphicsMagick++
