#include "../../Include/Logger.h"
#include <iostream>
#include "../../include/fileutils.h"

namespace clim{
	namespace system{
		
		



		void Logger::writeToLog(const std::string filepath, const std::string data){
			std::string fullPath = LOG + filepath;
			std::cout << data.c_str() << std::endl;
			fileutils::write_To_File(fullPath, data.c_str());
			
			
		}

		void Logger::writeToDebugLog(const std::string data){
			std::string DebugFile = "Debug.txt";
			std::string fullPath = LOG + DebugFile;
			fileutils::write_To_File(fullPath.c_str() , data.c_str());
		}

		void Logger::writeToGELog(const std::string data){
			std::string DebugFile = "GeneralError.txt";
			std::string fullPath = LOG + DebugFile;
			fileutils::write_To_File(fullPath.c_str(), data.c_str());
		}

		void Logger::writeToGLFWDLog(const std::string data){
			std::string DebugFile = "GLFWDebug.txt";
			std::string fullPath = LOG + DebugFile;
			fileutils::write_To_File(fullPath.c_str() , data.c_str());
		}
		void Logger::writeToGLEWDLog(const std::string data){
			std::string DebugFile = "GLEWDebug.txt";
			std::string fullPath = LOG + DebugFile;
			fileutils::write_To_File(fullPath.c_str() , data.c_str());
		}
		void Logger::writeToGLFWELog(const std::string data){
			std::string ErrorFile = "GLFWError.txt";
			std::string fullPath = LOG + ErrorFile;
			fileutils::write_To_File(fullPath.c_str() , data.c_str());
		}
		void Logger::writeToGLEWELog(const std::string data){
			std::string ErrorFile = "GLEWError.txt";
			std::string fullPath = LOG + ErrorFile;
			fileutils::write_To_File(fullPath.c_str(), data.c_str());
		}


	}
}
