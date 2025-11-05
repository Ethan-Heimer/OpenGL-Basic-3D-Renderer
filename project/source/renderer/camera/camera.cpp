#include "renderer/camera.h"
#include "glm/detail/qualifier.hpp"
#include "glm/exponential.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_geometric.hpp"
#include "glm/ext/quaternion_trigonometric.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/fwd.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include <iostream>

using namespace Renderer;

void Camera::SetPosition(float x, float y, float z){
    position.x = x;
    position.y = y;
    position.z = z;
}

void Camera::Translate(float x, float y, float z){
    position.x += x;
    position.y += y;
    position.z += z;
}

void Camera::Move(float speed){
    position += front * speed;
}

void Camera::Strafe(float speed){
    //get right vector
    glm::vec3 up{0, 1, 0};
    glm::vec3 right = glm::cross(front, up);

    position += right * speed;
}

void Camera::SetPitch(float theta){
    pitch = theta;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
}

void Camera::IncrementPitch(float theta){
    pitch += theta;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
}

void Camera::SetYaw(float theta){
    yaw = theta;
}

void Camera::IncrementYaw(float theta){
    yaw += theta;
}

glm::mat4 Camera::GetViewMatrix(){
    UpdateViewMatrix();
    return view;
}

void Camera::UpdateViewMatrix(){
    //this handles constructing the direction, right, and up vectors,
    //as well as creating a look at matrix
    //taking away the position variable from the target argument creates an
    //effect where the camera will always focus at a point   
    
    //update direction vector
    direction.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
    direction.y = glm::sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    //update front
    front = glm::normalize(direction);
    
    glm::vec3 up{0.0f, 1.0f, 0.0f};
    view = glm::lookAt(position, position + front, up);
}
