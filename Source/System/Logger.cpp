#include "../../Include/Logger.h"
#include "../../Include/console.h"
#include <iostream>
#include "../../Include/fileutils.h"

namespace clim{
	namespace system{
		
		
        void Logger::printToConsole(console *c, QString data){
            c->printToConsole(data);
        }


        void Logger::cwriteToLog(console *c,const std::string filepath, const std::string data){
			std::string fullPath = LOG + filepath;
            QString toFile = "To File: ";
            toFile.append(filepath.c_str());
            printToConsole(c,toFile);
            printToConsole(c,QString(data.c_str()));
			fileutils::write_To_File(fullPath, data.c_str());
			
			
		}

        void Logger::writeToLog(const std::string filepath, const std::string data){
            std::string fullPath = LOG + filepath;
            fileutils::write_To_File(fullPath, data.c_str());
        }

        void Logger::cwriteToDebugLog(console *c,const std::string data){
			std::string DebugFile = "Debug.txt";
            QString toFile = "To File: ";
            toFile.append(DebugFile.c_str());
            printToConsole(c,toFile);
            printToConsole(c,QString(data.c_str()));

			std::string fullPath = LOG + DebugFile;
			fileutils::write_To_File(fullPath.c_str() , data.c_str());
		}

        void Logger::cwriteToGELog( console *c,const std::string data){
			std::string DebugFile = "GeneralError.txt";

            QString toFile = "To File: ";
            toFile.append(DebugFile.c_str());
            printToConsole(c,toFile);
            printToConsole(c,QString(data.c_str()));

			std::string fullPath = LOG + DebugFile;    
			fileutils::write_To_File(fullPath.c_str(), data.c_str());
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



	}
}
