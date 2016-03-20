
//libraries
#include <QApplication>
#include <QString>
#include <QtGui>
#include <QMessageBox>

//User Defined
#include "Include/stringutils.h"
#include "Include/keyboard.h"
#include "Include/mouse.h"
#include "Include/platform.h"
#include "Include/screen.h"
#include "Include/Debugger.h"
#include "Include/Logger.h"
#include "Include/audio.h"
#include "Include/fileutils.h"
#include "Include/console.h"
#include "Include/engine.h"
#define VERSION "0.0.2.0"
#define ENGINETITLE "ClimLib"

//Lua Testing
#ifdef __WIN64
#include "Dependencies/lua-5.3.2/builds/mingw/include/lua.h"
#include "Dependencies/lua-5.3.2/builds/mingw/include/lauxlib.h"
#include "Dependencies/lua-5.3.2/builds/mingw/include/lualib.h"
#endif

#ifdef __WIN32
#include "Dependencies/lua-5.3.2/builds/mingw/include/lua.h"
#include "Dependencies/lua-5.3.2/builds/mingw/include/lauxlib.h"
#include "Dependencies/lua-5.3.2/builds/mingw/include/lualib.h"
#endif

#include "Dependencies/lua-5.3.2/src/lua.h"
#include "Dependencies/lua-5.3.2/src/lauxlib.h"
#include "Dependencies/lua-5.3.2/src/lualib.h"


using namespace clim;
using namespace graphics;
using namespace core;


QString ApplicationTitle;

int main(int argc, char *argv[])
{





    std::vector<std::string> test;
    std::string testing = "Hello world this is tokenization testing";
    test = stringUtils::tokenize(testing);


    Audio atest = Audio("Test","Test.wav");

    Engine engine("ClimLib ","0.0.2.0",true,argc,argv);
    engine.getConsole()->printToConsole("Inside main Function");


        for(unsigned int i= 0; i< test.size();i++){
        engine.getConsole()->printToConsole(test[i].c_str());
    }



    //test.play();
    system::keyboard keyboard(&engine);
    system::mouse mouse(&engine);
    engine.update();
//    ApplicationTitle += ENGINETITLE;
//    ApplicationTitle += " Version ";
//    ApplicationTitle += VERSION;
//    QApplication a(argc, argv);

//    system::console c;

//   // QMessageBox qmb;
//  //  qmb.show();
//   // qmb.setText("Initialization of the Engine");


//    c.show();
//   c.printToConsole("Initialization of ClimLib v 0.0.2.0");
//   QString platform = "Platform: ";
//   platform.append(QString(system::platformToString(system::detectPlatform()).c_str()));
//   c.printToConsole(platform);
//       system::logger.cwriteToDebugLog(&c,"Debugging the Logging system.");
//       system::logger.cwriteToDebugLog(&c,"This is a Git Kraken Test. V 0.0.2.1 push soon");

//    Screen s;
//      s.setupScreen(ApplicationTitle,640,480);
//      s.show();
//      test.play();

//      system::logger.cwriteToDebugLog(&c,std::to_string(s.x()).c_str());
//      system::logger.cwriteToDebugLog(&c,std::to_string(s.y()).c_str());

      return engine.exec();

}

