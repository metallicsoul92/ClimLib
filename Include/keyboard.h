#ifndef KEYBOARD
#define KEYBOARD

#include <QKeyEvent>


//User created
#include "engine.h"


namespace clim{


using namespace core;

    namespace system{




    class keyboard : public QObject {
        Q_OBJECT


        // QObject interface
    public:
       explicit keyboard();
        bool event(QEvent *event);
        bool eventFilter(QObject *object, QEvent *event);

    protected:

        Engine *engine;
    };

    }
}


#endif // KEYBOARD

