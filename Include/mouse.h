#ifndef MOUSE
#define MOUSE

//QT Related
#include <QMouseEvent>
#include <QObject>

//User Created
#include "MathFunctions.h"
#include "screen.h"
#include "inputdevice.h"



namespace clim{
    namespace system{

    class mouseDevice : InputDevice {
    Q_OBJECT


    public:
        mouseDevice(QObject *_parent);
        math::vec2<int> getCoordinates();
        QMouseEvent *getEvent();
        math::vec2i *getCoordinateAddress();
        void mousePressEvent(QMouseEvent *e);
        QEvent *poll();
        QString toQString();

    private:
        graphics::Screen *m_Screen;
        QMouseEvent *m_event;
        math::vec2<int> m_coordinates;
        };
    }
}



#endif // MOUSE

