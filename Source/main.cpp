#include <QApplication>
#include <QString>
#include <QtGui>
#include "Include/platform.h"
#include "Include/screen.h"
#include "Include/Debugger.h"
#include "Include/Logger.h"
#include "Include/audio.h"
#include "Include/fileutils.h"
#include "Include/console.h"
#include <QMessageBox>

#define VERSION "0.0.2.0"
#define ENGINETITLE "ClimLib"



using namespace clim;
using namespace graphics;
using namespace core;


QString ApplicationTitle;

int main(int argc, char *argv[])
{
    Audio test = Audio("Test","Test.wav");

    ApplicationTitle += ENGINETITLE;
    ApplicationTitle += " Version ";
    ApplicationTitle += VERSION;
    QApplication a(argc, argv);

    system::console c;

   // QMessageBox qmb;
  //  qmb.show();
   // qmb.setText("Initialization of the Engine");


    c.show();
   c.printToConsole("Initialization of ClimLib v 0.0.2.0");
   QString platform = "Platform: ";
   platform.append(QString(system::platformToString(system::detectPlatform()).c_str()));
   c.printToConsole(platform);
       system::logger.cwriteToDebugLog(&c,"Debugging the Logging system.");
    Screen s;
      s.setupScreen(ApplicationTitle,640,480);
      s.show();
      test.play();

      return a.exec();

}

