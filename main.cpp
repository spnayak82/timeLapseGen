#include <QtGui/QApplication>
#include<QDesktopWidget>
#include "timelapsegenmain.h"
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main(int argc, char *argv[])
{
    InitializeMagick(*argv);

    QApplication a(argc, argv);
    TimeLapseGenMain w;

    /* Move the main window to the center of screen */
    QRect screenGeometry = QApplication::desktop()->screenGeometry();

    int x = (screenGeometry.width()- w.width()) / 2;
    int y = (screenGeometry.height()- w.height()) / 2;

    w.move(x,y);

    /* Now show the main window */
    w.show();
    
    return a.exec();
}
