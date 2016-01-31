#include <QGuiApplication>
#include <QString>
#include <QtGui>
#include "Include/screen.h"

#define VERSION "0.0.2.0"
#define ENGINETITLE "ClimLib"

using namespace clim::graphics;




int main(int argc, char *argv[])
{
    QGuiApplication current;
    QString title = QString(ENGINETITLE);
    title+=" Version ";
    title+=VERSION;
   Screen s;
    s.initializet(title,640,640);

    return 0;
}

