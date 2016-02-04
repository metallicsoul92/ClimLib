#ifndef ENGINE
#define ENGINE

#include "screen.h"
#include "console.h"
#include <QApplication>
#include <QString>


namespace clim{
    namespace core{

        class Engine{


        public:
            Engine(QApplication *a,QString title,QString version, bool debug);



        private:
            QString EngineTitle;
            QString EngineVersion;
            bool isDebugging;
            graphics::Screen *screen;
            system::console *console;
            QApplication *application;
        };
    }
}
#endif //ENGINE

