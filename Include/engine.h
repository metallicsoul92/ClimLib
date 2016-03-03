#ifndef ENGINE
#define ENGINE

//QT Related
#include <QApplication>
#include <QString>


//User Created
#include "screen.h"
#include "console.h"


namespace clim{
    namespace core{



        class Engine: public QObject{
        Q_OBJECT;

        public:

          static Engine *getInstance();
          explicit Engine(Engine &e);
           explicit Engine(QApplication *a,QString title,QString version, bool debug);
          ~Engine();
            system::console *getConsole();
           void update();
        int exec();



        QString getEngineTitle();
        QString getEngineVersion();
        QApplication *getApplication();
        graphics::Screen *getScreen();

        private:

            bool isRunning;
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

