#ifndef MATERIAL_H
#define MATERIAL_H

#include "renderer/shader.h"
#include "renderer/texture.h"
#include <cwctype>

namespace Renderer{
    class Material{
        public:
            Material(Renderer::Texture* texture, Renderer::Shader* shader);

            void Use();
            Renderer::Shader* GetShader() const;

        private:
            Renderer::Texture* texture;
            Renderer::Shader* shader;
    };
}

#endif
