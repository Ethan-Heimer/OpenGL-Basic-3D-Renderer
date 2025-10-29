#include "utils/color.h"

using namespace Utils;

const char* Color::ASNIColorCodes[]{
    "\e[30m",
    "\e[31m",
    "\e[32m",
    "\e[33m",
    "\e[34m",
    "\e[35m",
    "\e[36m",
    "\e[37m",
};

const char* Color::TextColor(enum TextColor color){
   return ASNIColorCodes[color]; 
}
