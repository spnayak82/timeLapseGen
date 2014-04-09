#-------------------------------------------------
#
# Project created by QtCreator 2014-03-18T14:00:06
#
#-------------------------------------------------

#  timeLapseGen is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

QT       += core gui

TARGET = timeLapseGen
TEMPLATE = app

CONFIG += x86

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


DEPENDPATH += $$PWD/

INCLUDEPATH += /usr/include/GraphicsMagick/

OTHER_FILES +=

unix:!macx:!symbian: LIBS += -lGraphicsMagick++
