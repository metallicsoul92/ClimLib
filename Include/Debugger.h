#pragma once
#include <string>
#include <qdebug.h>
#include "console.h"

namespace clim{
	 namespace system{
		class Debugger
		{
		public:
            Debugger(system::console* c);

            system::console *m_console;
            QString *m_debugString;
            QDebug m_debug;

            static void printToScreen(std::string line);
            void redirectToConsole(QString data);
            void setDebug();
            QDebug operator<<(QString data);
		};

	}
}
