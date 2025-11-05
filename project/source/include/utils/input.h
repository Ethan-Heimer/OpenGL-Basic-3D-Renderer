#ifndef INPUT_H
#define INPUT_H

#include "GLFW/glfw3.h"
#include "glm/fwd.hpp"

namespace Utils{
    class Input{
        public:
            static void Init(GLFWwindow* window);

            static bool GetKey(unsigned int keyCode);

            static void MousePosition(float* x, float* y);
            static void MouseDelta(float* x, float* y);

            static void PollMouseDelta();

        private:
            static GLFWwindow* mainWindow;

            static float mouseX;
            static float mouseY;

            static float deltaMouseX;
            static float deltaMouseY;

            static float lastMouseX;
            static float lastMouseY;

            static bool deltaCalculated;

            static void mouse_callback(GLFWwindow* window, double x, double y);
    };
}

#endif
