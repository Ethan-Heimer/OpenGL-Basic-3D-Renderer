#ifndef CAMERA_H
#define CAMERA_H

#include "glm/ext/vector_float3.hpp"
#include "glm/fwd.hpp"
#include "renderer/transform.h"
namespace Renderer{
    class Camera{
        public:
            void SetPosition(float x, float y, float z);  
            void Translate(float x, float y, float z); 

            void Move(float speed);
            void Strafe(float speed);

            void SetPitch(float theta);
            void IncrementPitch(float theta);

            void SetYaw(float theta);
            void IncrementYaw(float theta);

            glm::mat4 GetViewMatrix();

        private:
            glm::vec3 position{0.0f, 0.0f, 3.0f};
            glm::vec3 front{0.0, 0.0f, -1.0};

            float pitch = 0;
            float yaw = -90.0f;

            glm::vec3 direction{0, 0, 0};

            glm::mat4 view{1.0f};

            //view matrix
            void UpdateViewMatrix();

    };
}

#endif
