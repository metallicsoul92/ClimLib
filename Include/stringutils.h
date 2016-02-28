#ifndef STRINGUTILS
#define STRINGUTILS


//C++ Headers
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
//QT Headers

//User Defined Headers

namespace clim{

    class stringUtils{

    public:
   static std::vector<std::string> tokenize(std::string & src){
       std::vector<std::string> temp;
       char * copy = strdup(src.c_str());
       char * pch = strtok(copy, " ");
       while(pch != NULL){
           temp.push_back(pch);
           pch = strtok (NULL, " ");
       }
       return temp;
   }



    };


}






#endif // STRINGUTILS

