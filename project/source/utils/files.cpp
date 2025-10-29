#include "utils/color.h"
#include "utils/file.h"

#include "utils/error.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace Utils;

void Utils::LoadFile(std::string path, std::string* outPut){ 
    std::ifstream fileStream{path};

    if(fileStream.fail()){
        Errors::DisplayError("FILE ERROR", RED, "Could not read " + path); 
        *outPut = "\0";
        return;
    }
    
    std::stringstream stringStream;

    stringStream << fileStream.rdbuf();

    *outPut = stringStream.str();

    fileStream.close(); 
}
