#ifndef INPUT_H
#define INPUT_H

#include "GLFW/glfw3.h"

namespace Utils{
    class Input{
        public:
            static void Init(GLFWwindow* window);

            static bool GetKey(unsigned int keyCode);

            /*
            void processInput(GLFWwindow *window)
            {
                if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                    glfwSetWindowShouldClose(window, true);
            }
            */

        private:
            static GLFWwindow* mainWindow;
    };
}

#endif
