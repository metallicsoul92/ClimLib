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
    ~console();
    void printToConsole(QString data);
   static void sprintToConsole(QString data);
    Ui::console *getConsole(){return ui;}

public slots:
    void recieveInput(QString data);



private:
   Ui::console *ui;


};
}
}
#endif // CONSOLE_H
