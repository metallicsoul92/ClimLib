#include "../../Include/keyboard.h"
#include "../../Include/Logger.h"
#include <QEvent>

namespace clim{
    namespace system{

    keyboard::keyboard() : engine(core::Engine::getInstance())
    {
        engine->getScreen()->installEventFilter(this);
    }

    bool keyboard::event(QEvent *event)
    {
        return this->event(event);
    }

    bool keyboard::eventFilter(QObject *object, QEvent *event)
    {
           if ( event->type() == QEvent::KeyPress ) {  // key press
               QKeyEvent *k = (QKeyEvent*)event;
               QString data = "Key Press: ";
               data.append(k->text());
              this->engine->getConsole()->printToConsole(data);
               return true;                        // eat event
           }
           return eventFilter( object, event );    // standard event processing
       }


    }
}



