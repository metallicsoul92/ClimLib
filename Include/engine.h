#ifndef ENGINE
#define ENGINE

//QT Related
#include <QApplication>
#include <QString>


//User Created
#include "screen.h"
#include "console.h"
#include "Debugger.h"

namespace clim{
    namespace core{



        class Engine: public QApplication{
        Q_OBJECT

        public:

          static Engine *getInstance();
          explicit Engine(const Engine &e, int &argc, char **argv);
           explicit Engine(QString title, QString version, bool debug,  int &argc, char** argv);
          ~Engine();
            system::console *getConsole()const;
            system::console *Console();
           void update();



        QString getEngineTitle()const;
        QString getEngineVersion()const;
        graphics::Screen *getScreen()const;

        QString& EngineTitle();
        QString& EngineVersion();
        graphics::Screen* ScreenPtr();

        private:

            bool isRunning;

            system::Debugger debug;
            QString *m_debugString;
           QString m_engineTitle;
            QString m_engineVersion;
             bool isDebugging;
            graphics::Screen *m_screen;
            system::console *m_console;

        };
    }
}
#endif //ENGINE

