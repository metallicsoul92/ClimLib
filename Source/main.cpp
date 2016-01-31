#include <QApplication>
#include <QString>
#include <QtGui>
#include "Include/screen.h"
#include "Include/audio.h"
#define VERSION "0.0.2.0"
#define ENGINETITLE "ClimLib"



using namespace clim;
using namespace graphics;
using namespace core;


QString ApplicationTitle;

int main(int argc, char *argv[])
{
    Audio test = Audio("Test","../Assets/Audio/Test.wav");

    ApplicationTitle += ENGINETITLE;
    ApplicationTitle += " Version ";
    ApplicationTitle += VERSION;
    QApplication a(argc, argv);
      Screen s;
      s.setupScreen(ApplicationTitle,640,480);
      s.show();
      test.play();

      return a.exec();

}

