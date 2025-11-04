#include "utils/input.h"

GLFWwindow* Utils::Input::mainWindow = NULL;

void Utils::Input::Init(GLFWwindow *window){
    mainWindow = window;
}

bool Utils::Input::GetKey(unsigned int keyCode){
    return glfwGetKey(mainWindow, keyCode) == GLFW_PRESS;
}
