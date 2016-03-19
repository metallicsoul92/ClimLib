#include "../../Include/engine.h"
#include "../../Include/platform.h"
#include "../../Include/keyboard.h"
#include <Qt>
namespace clim{
    namespace core{

    Engine::Engine(const Engine &e) : QObject()
    {
        m_engineTitle = e.getEngineTitle();
        m_engineVersion = e.getEngineVersion();
        m_screen = e.getScreen();
        m_application = e.getApplication();
        m_console = e.getConsole();


    }

    Engine::Engine(QApplication *a,QString title,QString version, bool debug) :QObject(), m_engineTitle(title),
    m_engineVersion(version),isDebugging(debug), m_application(a){

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
        m_screen->show();
        isRunning= true;


        connect(m_screen,SIGNAL(destroyed()),m_application,SLOT(quit()));
        connect(m_screen,SIGNAL(destroyed()),m_console,SLOT(close()));
    }

    Engine::~Engine()
    {
        m_application->exit();
        m_screen->destroy();
        delete this;
    }

    system::console *Engine::getConsole() const{return m_console;}

    system::console *Engine::Console()
    {
        return m_console;
    }

    int Engine::exec(){
        return m_application->exec();
    }

    QString Engine::getEngineTitle()const{return m_engineTitle;}

    QString Engine::getEngineVersion()const{return m_engineVersion;}

    QApplication *Engine::getApplication()const{return m_application;}

    graphics::Screen *Engine::getScreen()const{return m_screen;}

    QString& Engine::EngineTitle()
    {
        return m_engineTitle;
    }

    QString& Engine::EngineVersion(){return m_engineVersion;}

    QApplication* Engine::ApplicationPtr(){return m_application;}

    graphics::Screen *Engine::ScreenPtr(){return m_screen;}


    void Engine::update(){
        while(isRunning){

            if(!m_screen->isOpen){
                isRunning = false;
            }

           // Grab Logic information

            //Update graphics

            //run Execute
            exec();
         }
    }


    }
}
