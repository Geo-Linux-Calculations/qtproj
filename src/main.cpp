#include <QApplication>
#include "qtproj.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtProj w;
    w.show();
    return a.exec();
}
