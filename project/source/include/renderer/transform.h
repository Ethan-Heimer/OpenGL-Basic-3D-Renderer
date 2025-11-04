#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/ext/matrix_float4x4.hpp"
namespace Renderer{
    class Transform{
        public:
            void SetPosition(float x, float y, float z);
            void SetScale(float x, float y, float z);
            void SetRotation(float x, float y, float z);

            const glm::mat4 GetTransformationMatrix() const;

        private:
            glm::mat4 transformMatrix{1.0f};
            glm::mat4 rotationMatrix{1.0f};
            glm::mat4 scaleMatrix{1.0f};
    };
}

#endif
