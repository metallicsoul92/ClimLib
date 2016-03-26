#include "../../Include/engine.h"
#include "../../Include/platform.h"
#include "../../Include/keyboard.h"
#include <Qt>
namespace clim{
    namespace core{

    Engine::Engine(const Engine &e,  int &argc, char** argv):QApplication(argc,argv)
    {
        m_engineTitle = e.getEngineTitle();
        m_engineVersion = e.getEngineVersion();
        m_screen = e.getScreen();
        m_console = e.getConsole();
        m_debug = e.getDebug();


    }

    Engine::Engine(QString title,QString version, bool debug, int &argc, char** argv) :QApplication(argc, argv), m_engineTitle(title),
    m_engineVersion(version),isDebugging(debug){

        this->m_screen = new graphics::Screen;
        this->m_console = new system::console;
        QString at;
        at += this->m_engineTitle;
        at += " Version ";
        at += this->m_engineVersion;
        m_screen->setupScreen(at,640,480);// I need to abstract this more for better customization. Create an int width and height or even get into Display Sizes as vec2?
        if(this->isDebugging){
        m_console->show();
    }
        QString plat;
        plat = "Platform: ";
        plat.append(QString(system::platformToString(system::detectPlatform()).c_str()));
        m_console->printToConsole("Initialization of ClimLib v 0.0.2.0");
        m_console->printToConsole(plat);
        m_console->printToConsole("GL Version: (X:Major Y:Minor)");
        m_console->printToConsole(m_screen->oglfversion().ToString().c_str());
        m_screen->show();
        isRunning= true;


        m_debug=  new system::Debugger(Console());
        connect(m_screen,SIGNAL(destroyed()),m_console,SLOT(close()));
    }

    Engine::~Engine()
    {
        m_screen->destroy();
        delete this;
    }

    system::console *Engine::getConsole() const{return m_console;}

    system::console *Engine::Console()
    {
        return m_console;
    }


    QString Engine::getEngineTitle()const{return m_engineTitle;}

    QString Engine::getEngineVersion()const{return m_engineVersion;}

    graphics::Screen *Engine::getScreen()const{return m_screen;}

    QString& Engine::EngineTitle()
    {
        return m_engineTitle;
    }

    QString& Engine::EngineVersion(){return m_engineVersion;}

    graphics::Screen *Engine::ScreenPtr(){return m_screen;}

    system::Debugger *Engine::getDebug() const
    {
        return m_debug;
    }

    system::Debugger *Engine::debugger()
    {
        return m_debug;
    }


    void Engine::update(){
        while(isRunning){

            if(!m_screen->isOpen){
                isRunning = false;
                exit(0);
            }

           // Grab Logic information

            //Update graphics

            //run Execute
            exec();
         }
    }


    }
}
