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
          explicit Engine(const Engine &e);
           explicit Engine(QApplication *a,QString title,QString version, bool debug);
          ~Engine();
            system::console *getConsole()const;
            system::console *Console();
           void update();
        int exec();



        QString getEngineTitle()const;
        QString getEngineVersion()const;
        QApplication *getApplication()const;
        graphics::Screen *getScreen()const;

        QString& EngineTitle();
        QString& EngineVersion();
        QApplication* ApplicationPtr();
        graphics::Screen* ScreenPtr();

        private:

            bool isRunning;
            QString m_engineTitle;
            QString m_engineVersion;
            bool isDebugging;
            graphics::Screen *m_screen;
            system::console *m_console;
            QApplication *m_application;

        };
    }
}
#endif //ENGINE

