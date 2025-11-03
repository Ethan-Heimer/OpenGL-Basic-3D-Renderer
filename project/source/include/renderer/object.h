#ifndef OBJECT_H
#define OBJECT_H

#include "renderer/material.h"
#include "renderer/mesh.h"
#include "renderer/transform.h"
namespace Renderer{
    class Object{
        public:
            Object(Renderer::Mesh* mesh, Renderer::Material* material);
            ~Object();

            Renderer::Transform* GetTransform() const;
            Renderer::Mesh* GetMesh() const;
            Renderer::Material* GetMaterial() const;
            
        private:
            Renderer::Material* material;
            Renderer::Mesh* mesh;
            Renderer::Transform* transform;
    };
}

#endif
