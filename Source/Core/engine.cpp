#include "../../Include/engine.h"
#include "../../Include/platform.h"
#include "../../Include/keyboard.h"
#include <Qt>
namespace clim{
    namespace core{

    Engine::Engine(Engine &e) : QObject()
    {
        EngineTitle = e.getEngineTitle();
        EngineVersion = e.getEngineVersion();
        screen = e.getScreen();
        application = e.getApplication();
        console = e.getConsole();
        screen = e.getScreen();


    }

    Engine::Engine(QApplication *a,QString title,QString version, bool debug) : EngineTitle(title),
    EngineVersion(version),isDebugging(debug), application(a){

        this->screen = new graphics::Screen;
        this->console = new system::console;
        QString at;
        at += this->EngineTitle;
        at += " Version ";
        at += this->EngineVersion;
        screen->setupScreen(at,640,480);// I need to abstract this more for better customization. Create an int width and height or even get into Display Sizes as vec2?
        if(this->isDebugging){
        console->show();
    }
        QString plat;
        plat = "Platform: ";
        plat.append(QString(system::platformToString(system::detectPlatform()).c_str()));
        console->printToConsole("Initialization of ClimLib v 0.0.2.0");
        console->printToConsole(plat);
        screen->show();
        isRunning= true;


        connect(screen,SIGNAL(destroyed()),application,SLOT(quit()));
        connect(screen,SIGNAL(destroyed()),console,SLOT(close()));
    }

    system::console *Engine::getConsole(){return console;}

    int Engine::exec(){
        return application->exec();
    }

    QString Engine::getEngineTitle(){return EngineTitle;}

    QString Engine::getEngineVersion(){return EngineVersion;}

    QApplication *Engine::getApplication(){return application;}

    graphics::Screen *Engine::getScreen(){return screen;}




    void Engine::update(){
        while(isRunning){

            if(!screen->isOpen){
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
