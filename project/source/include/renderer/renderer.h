#ifndef RENDERER_H
#define RENDERER_H

#include "renderer/camera.h"
#include "renderer/object.h"
namespace Renderer{
    class Renderer{
        public:
            static void Draw(const Object& object, Camera& camera);
    };
}

#endif
