#ifndef INPUT_H
#define INPUT_H

#include "GLFW/glfw3.h"

namespace Utils{
    class Input{
        public:
            static void Init(GLFWwindow* window);

            static bool GetKey(unsigned int keyCode);

        private:
            static GLFWwindow* mainWindow;
    };
}

#endif
