#pragma once
#include <string>
#include <qdebug.h>
#include "console.h"

namespace clim{
	 namespace system{
		class Debugger
		{
		public:
            Debugger(system::console& c);

            QDebug debug;
            QString debugString;
            system::console &console;
            static void printToScreen(std::string line);
            void redirectToConsole(QString data);
            void setDebug();
            QDebug operator<<(QString data);
		};

	}
}
