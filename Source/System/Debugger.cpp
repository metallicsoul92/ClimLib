#include "../../Include/Debugger.h"
#include <iostream>
#include <ctime>
#include "../../Include/Logger.h"

namespace clim
{
	namespace system
	{

    Debugger::Debugger(console *c):m_console(c),m_debugString(new QString()), m_debug(m_debugString)
    {
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
        m_console->printToConsole(data);
    }

    QDebug Debugger::operator<<(QString data)
    {
        m_debug << data;
        redirectToConsole(data);
        return m_debug;
    }



	}
}
