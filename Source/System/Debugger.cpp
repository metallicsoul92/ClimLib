#include "../../Include/Debugger.h"
#include <iostream>
#include <ctime>
#include "../../Include/Logger.h"

namespace clim
{
	namespace system
	{

    Debugger::Debugger(system::console &c,QDebug &obj)
    {
        console = c;
        debug = obj;
    }

    void Debugger::printToScreen(std::string line)
		{
			time_t t = time(nullptr);
			tm *timen = localtime(&t);
			std::string fileDate;
			fileDate = std::to_string(timen->tm_mon +1);
			fileDate += "-";
			fileDate += std::to_string(timen->tm_mday);
			fileDate += ".txt";
            logger.writeToLog(fileDate, line);
            logger.writeToLog("General.txt",line);
    }

    void Debugger::redirectToConsole(QString data)
    {
        debug << data;
        console.printToConsole(data);
    }

    QDebug Debugger::operator<<(QString data)
    {
        redirectToConsole(data);
    }



	}
}
