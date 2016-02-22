#include "../../Include/mouse.h"
#include "../../Include/Logger.h"
#include <QEvent>

namespace clim{
    namespace system{

    mouse::mouse(Engine *engine) : engine(engine)
    {
        for(int i = 0; i < MAX_MOUSE_KEYS;i++){
            m_button[i] = false;
        }
        engine->getScreen()->installEventFilter(this);
    }

    bool mouse::event(QEvent *event)
    {
        return this->event(event);
    }

    bool mouse::eventFilter(QObject *object, QEvent *event)
    {
   QString button;
        //TODO: ADD custom keys like : Key Pressed: Left_Arrow

         if(event->type() == QEvent::MouseMove){
           QMouseEvent* e = (QMouseEvent *)event;
             m_position.x = e->x();
             m_position.y = e->y();
             QString moveEvent = "Mouse Moved: ";
             moveEvent.append("X: ");
             QString x = std::to_string(m_position.x).c_str();
             moveEvent.append(x);
             moveEvent.append(", ");
             moveEvent.append("Y: ");
             QString y = std::to_string(m_position.y).c_str();
             moveEvent.append(y);
             engine->getConsole()->printToConsole(moveEvent);
           }

         else if(event->type() == QEvent::MouseButtonPress){
             QMouseEvent* e = (QMouseEvent *)event;
               m_position.x = e->x();
               m_position.y = e->y();


               switch(e->button()){
               case Qt::LeftButton:
                   button = "Left button";
                   m_button[0] = true;
                   break;
               case Qt::ExtraButton4:
                   break;
               case Qt::ExtraButton5:
                   break;
               case Qt::ExtraButton6:
                   break;
               case Qt::ExtraButton7:
                   break;
               case Qt::ExtraButton8:
                   break;
               case Qt::ExtraButton9:
                   break;
               case Qt::ExtraButton10:
                   break;
               case Qt::ExtraButton11:
                   break;
               case Qt::ExtraButton12:
                   break;
               case Qt::ExtraButton13:
                   break;
               case Qt::ExtraButton14:
                   break;
               case Qt::ExtraButton15:
                   break;
               case Qt::ExtraButton16:
                   break;
               case Qt::ExtraButton17:
                   break;
               case Qt::ExtraButton18:
                   break;
               case Qt::ExtraButton19:
                   break;
               case Qt::ExtraButton20:
                   break;
               case Qt::ExtraButton21:
                   break;
               case Qt::ExtraButton22:
                   break;
               case Qt::ExtraButton23:
                   break;
               case Qt::MouseButtonMask:
                   break;
               case Qt::NoButton:
                   break;
               case Qt::AllButtons:
                   button = "All buttons";
                   for(int i = 0 ; i< MAX_MOUSE_KEYS; i++){
                       m_button[i] = true;
                   }
                   break;
               case Qt::RightButton:
                   button = "Right button";
                   m_button[2] = true;
                   break;
               case Qt::MiddleButton:
                   button = "Middle button";
                   m_button[1] = true;
                   break;
               case Qt::ExtraButton1:
                   m_button[4] = true;
                   button = "Extra button 1";
                   break;
               case Qt::ExtraButton2:
                   m_button[5] = true;
                   button = "Extra button 2";
                   break;
               case Qt::ExtraButton3:
                   m_button[6] = true;
                   button = "Extra button 3";
                   break;
               }

               QString moveEvent = "Mouse Moved and Pressed: ";
               moveEvent.append("X: ");
               QString x = std::to_string(m_position.x).c_str();
               moveEvent.append(x);
               moveEvent.append(", ");
               moveEvent.append("Y: ");
               QString y = std::to_string(m_position.y).c_str();
               moveEvent.append(y);
               moveEvent.append(", ");
               moveEvent.append("Pressed: ");
               moveEvent.append(button);



              engine->getConsole()->printToConsole(moveEvent);
         }
           return QObject::eventFilter( object, event );    // standard event processing
       }


    }
}




