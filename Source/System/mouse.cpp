#include "../../Include/mouse.h"

#include <string>
#include <stdlib.h>
#include <Qt>
#include <QString>
namespace clim{
namespace system{

mouseDevice::mouseDevice(QObject *_parent):InputDevice(_parent){
    m_coordinates = math::create_vec2<int>(0,0);
}

math::vec2<int> mouseDevice::getCoordinates(){
    return m_coordinates;
}

QMouseEvent *mouseDevice::getEvent(){
    return m_event;
}

    QEvent *mouseDevice::poll(){
        return (QEvent *)m_event;
    }

    QString mouseDevice::toQString(){
        QString temp;

        QString x = "X: ";
        x += getCoordinates().x;
        x.append("\n");

        QString y = "Y: ";
        y += getCoordinates().y;
        y.append("\n");

        QString event = "Event: ";

        switch(m_event->button()){
        case Qt::NoButton:
            event.append("No Button\n");
            break;
        case Qt::LeftButton:
             event.append("Left Button\n");
            break;
        case Qt::RightButton:
             event.append("Right Button\n");
            break;
        case Qt::MidButton:
             event.append("Middle Button\n");
            break;
        case Qt::XButton1:
             event.append("X Button 1\n");
            break;
        case Qt::XButton2:
            event.append("X Button 2\n");
            break;
        }



        temp.append("MouseEvent:\n");
        temp.append(x);
        temp.append(y);
        temp.append(event);

        return temp;
    }


 void mouseDevice::mousePressEvent(QMouseEvent *e){
     switch(e->buttons()){
     case Qt::LeftButton :
         m_coordinates.x = e->globalX();
         m_coordinates.y = e->globalY();
         m_event = e;
         break;
     }
 }


}
}
