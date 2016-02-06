#ifndef INPUTDEVICE
#define INPUTDEVICE

//QTRelated Headers
#include <QObject>
//UserCreated Headers
namespace clim{
    namespace system{

        class InputDevice : public QObject{
         Q_OBJECT

        public:
        InputDevice(QObject *parent=0);

       };
    }
}

#endif // INPUTDEVICE

