#include "../../Include/keyboard.h"
#include "../../Include/Logger.h"
#include <QEvent>

namespace clim{
    namespace system{

    keyboard::keyboard(Engine *engine) : m_engine(engine)
    {
        for(int i = 0; i < MAX_KEYBOARD_KEYS;i++){
            m_key[i] = false;
        }
        m_engine->getScreen()->installEventFilter(this);
    }

    bool keyboard::event(QEvent *event)
    {
        return this->event(event);
    }

    bool keyboard::eventFilter(QObject *object, QEvent *event)
    {

        //TODO: ADD custom keys like : Key Pressed: Left_Arrow

           if ( event->type() == QEvent::KeyPress ) {  // key press
               QKeyEvent *k = (QKeyEvent*)event;
               m_key[k->nativeVirtualKey()] = true;
               QString data = "Key Press: ";
               data.append(k->text());
              this->m_engine->getConsole()->printToConsole(data);
               return true;                        // eat event
           }
           else if( event->type() == QEvent::KeyRelease){
               QKeyEvent *k = (QKeyEvent*)event;
               m_key[k->nativeVirtualKey()] = false;
               QString data = "Key release ";
               this->m_engine->getConsole()->printToConsole(data);
            return true;
           }
           return QObject::eventFilter( object, event );    // standard event processing
       }


    }
}



