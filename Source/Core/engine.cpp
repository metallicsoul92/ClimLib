#include "../../Include/engine.h"
#include "../../Include/platform.h"

namespace clim{
    namespace core{

    Engine::Engine(QApplication *a,QString title,QString version, bool debug) : EngineTitle(title),
    EngineVersion(version),isDebugging(debug), application(a) , mouse(new system::mouseDevice(0)){

        this->screen = new graphics::Screen();
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
        screen->show();

        isRunning= true;
    }

    void Engine::update(){
        while(isRunning){
            console->printToConsole(mouse->toQString());
         }
    }


    }
}
