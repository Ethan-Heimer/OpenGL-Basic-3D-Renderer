#include "utils/input.h"
#include <GLFW/glfw3.h>

float Utils::Input::mouseX = 0;
float Utils::Input::mouseY = 0;

float Utils::Input::lastMouseX = 0;
float Utils::Input::lastMouseY = 0;

float Utils::Input::deltaMouseX = 0;
float Utils::Input::deltaMouseY = 0;

bool Utils::Input::deltaCalculated = true;

GLFWwindow* Utils::Input::mainWindow = NULL;

void Utils::Input::Init(GLFWwindow *window){
    mainWindow = window;

    //init last mouse pos to center of window
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glfwSetCursorPosCallback(window, mouse_callback);

    mouseX = width/2.0f;
    mouseY = height/2.0f;

    lastMouseX = width/2.0f;
    lastMouseY = height/2.0f;
}

bool Utils::Input::GetKey(unsigned int keyCode){
    return glfwGetKey(mainWindow, keyCode) == GLFW_PRESS;
}

void Utils::Input::MousePosition(float* x, float* y){
   *x = mouseX;
   *y = mouseY;
}

void Utils::Input::MouseDelta(float* x, float* y){
    *x = deltaMouseX;
    *y = deltaMouseY;
}

void Utils::Input::PollMouseDelta(){ 
    if(!deltaCalculated){
        deltaMouseX = lastMouseX - mouseX; 
        deltaMouseY = lastMouseY - mouseY; 

        deltaCalculated = true;
    } else {
        deltaMouseX = 0;
        deltaMouseY = 0;
    }
}

void Utils::Input::mouse_callback(GLFWwindow* window, double x, double y){
    lastMouseX = mouseX;
    lastMouseY = mouseY;

    mouseX = x;
    mouseY = y;
   
    deltaCalculated = false;
}

