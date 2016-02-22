#ifndef KEYBOARD
#define KEYBOARD

#include <QKeyEvent>



#define MAX_KEYBOARD_KEYS 256

//User created
#include "engine.h"


namespace clim{


using namespace core;

    namespace system{




    class keyboard : public QObject {
        Q_OBJECT


        // QObject interface
    public:
       explicit keyboard(Engine* engine);
        bool event(QEvent *event);
        bool eventFilter(QObject *object, QEvent *event);

    protected:
        bool m_key[MAX_KEYBOARD_KEYS];
        Engine *engine;
    };

    }
}


#endif // KEYBOARD

