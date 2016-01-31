#include "../../Include/Debugger.h"
#include <iostream>
#include <ctime>
#include "../../Include/Logger.h"

namespace clim
{
	namespace system
	{
		
		void Debugger::printToScreen(std::string line)
		{
#ifdef DEBUG
			time_t t = time(nullptr);
			tm *timen = localtime(&t);
			std::string fileDate;
			fileDate = std::to_string(timen->tm_mon +1);
			fileDate += "-";
			fileDate += std::to_string(timen->tm_mday);
			fileDate += ".txt";
			logger.writeToLog(fileDate, line);
#endif
		}


	}
}
