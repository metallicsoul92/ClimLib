#ifndef LOGGER_H_
#define LOGGER_H_
#include <iostream>


#define LOG "Log/"

namespace clim{
	namespace system{


		class Logger
		{
		public:
	
			~Logger(){  };

			void writeToLog(const std::string filepath, const std::string data);
			void writeToGELog(const std::string data);			
			void writeToDebugLog(const std::string data);
			void writeToGLFWDLog(const std::string data);
			void writeToGLEWDLog(const std::string data);
			void writeToGLFWELog(const std::string data);
			void writeToGLEWELog(const std::string data);


			
		};

		static Logger logger;
	}
}
#endif