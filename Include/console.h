#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include "Logger.h"


namespace Ui {
class console;
}


namespace clim{
namespace system{

class console : public QWidget
{
    Q_OBJECT


public:
    explicit console(QWidget *parent = 0);
    explicit console(console&& con);
    ~console();
    void printToConsole(QString data);
    Ui::console *getConsole()const {return ui;}
    Ui::console *Console(){return ui;}

    template<typename t>
    void operator<<(t data){ printToConsole(QString(data));}
    console & operator=(console&& other);

public slots:
    void recieveInput(QString data);



private:
   Ui::console *ui;


};
}
}
#endif // CONSOLE_H
