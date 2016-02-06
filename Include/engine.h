#ifndef ENGINE
#define ENGINE

//QT Related
#include <QApplication>
#include <QString>


//User Created
#include "screen.h"
#include "console.h"
#include "mouse.h"
namespace clim{
    namespace core{



        class Engine{


        public:
            Engine(QApplication *a,QString title,QString version, bool debug);
            system::console *getConsole(){return console;}
            system::mouseDevice *getMouse(){return mouse;}
           void update();


        private:
            bool isRunning;
            QString EngineTitle;
            QString EngineVersion;
            bool isDebugging;
            graphics::Screen *screen;
            system::console *console;
            QApplication *application;
            system::mouseDevice *mouse;
        };
    }
}
#endif //ENGINE

