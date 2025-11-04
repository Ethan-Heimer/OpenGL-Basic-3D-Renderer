#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/trigonometric.hpp"
#include "renderer/transform.h"

using namespace Renderer;

void Transform::SetPosition(float x, float y, float z){
    transformMatrix = glm::translate(transformMatrix, glm::vec3(x, y, z));
}

void Transform::SetRotation(float x, float y, float z){
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(x), glm::vec3(1.0, 0.0, 0.0));
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(y), glm::vec3(0.0, 1.0, 0.0));
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(z), glm::vec3(0.0, 0.0, 1.0)); 
}

void Transform::SetScale(float x, float y, float z){
    scaleMatrix = glm::scale(scaleMatrix, glm::vec3(x, y, z));
}

const glm::mat4 Transform::GetTransformationMatrix() const {
    return transformMatrix * rotationMatrix * scaleMatrix;
}
