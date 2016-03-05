#ifndef MOUSE
#define MOUSE
#include <QKeyEvent>



#define MAX_MOUSE_KEYS 16

//User created
#include "engine.h"


namespace clim{


using namespace core;

    namespace system{




    class mouse : public QObject {
        Q_OBJECT


        // QObject interface
    public:
       explicit mouse(Engine* engine);
        bool event(QEvent *event);
        bool eventFilter(QObject *object, QEvent *event);

    protected:
        math::vec2<int> m_position;
        bool m_button[MAX_MOUSE_KEYS];
        Engine *engine;
    };

    }
}

#endif // MOUSE

