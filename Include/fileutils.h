#pragma once

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
namespace clim{

    class fileutils{


    public:

        //Will use this when I start implementing shader programs in OpenGL
        static std::string read_file(const char* filepath)
        {
            FILE* file = fopen(filepath, "rt");
            fseek(file, 0, SEEK_END);
            unsigned long length = ftell(file);
            char* data = new char[length + 1];
            std::memset(data, 0, length + 1);
            fseek(file, 0, SEEK_SET);
            fread(data, 1, length, file);
            fclose(file);

            std::string result(data);
            delete[] data;
            return result;
        }

		static void write_To_File(std::string filepath, std::string data){
			std::ofstream file;
			file.open(filepath.c_str(), std::ios::app);
			file << data.c_str();
			file << std::endl;
			file.close();

		}
    };


}
