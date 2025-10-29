#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include "utils/color.h"

namespace Utils{
    class Errors{
        public:
            static void DisplayError(std::string heading, TextColor color, std::string message);
    };
}

#endif
