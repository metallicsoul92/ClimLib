#include "../../Include/console.h"
#include "ui_console.h"


namespace clim{
namespace system{


console::console(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::console)
{
    ui->setupUi(this);

}

console::console(console &&con) : ui(std::move(con.Console()))
{

}


console::~console()
{
    delete ui;
}

    void console::printToConsole(QString data){
        ui->outputField->appendPlainText(data);
        ui->outputField->appendHtml("\n");
    }

    void console::operator<<(const char *data)
    {
           this->printToConsole(data);
    }






    void console::recieveInput(QString data){
        this->printToConsole(data);
    }

}
}

