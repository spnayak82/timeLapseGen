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
