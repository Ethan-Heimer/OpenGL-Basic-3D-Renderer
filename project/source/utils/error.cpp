#include "utils/error.h"
#include "utils/color.h"
#include <iostream>

using namespace Utils;

void Errors::DisplayError(std::string heading, TextColor color, std::string message){
    std::cerr << Color::TextColor(color) 
              << '['
              << heading 
              << ']'
              << '\n' 
              << Color::TextColor(WHITE)
              << message 
              << '\n'
              << std::endl;
}
