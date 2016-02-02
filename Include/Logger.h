#ifndef LOGGER_H_
#define LOGGER_H_
#include <iostream>
#include "console.h"
#include <QString>

#define LOG "../../../../Log/"

namespace clim{
	namespace system{
//foward declare
    class console;

		class Logger
		{
		public:
	
			~Logger(){  };

            void cwriteToLog( console *c, const std::string filepath, const std::string data);
             void writeToLog(const std::string filepath, const std::string data);
            void cwriteToGELog(console *c,const std::string data);
            void cwriteToDebugLog(console *c,const std::string data);
            void writeToGELog(const std::string data);
            void writeToDebugLog(const std::string data);
            void printToConsole(console *c,QString data);


		};

        static Logger logger;
	}
}
#endif
