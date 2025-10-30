#include "renderer/object.h"

using namespace Renderer;

Object::Object(Transform* transform, Mesh* mesh, Material* material)
 : transform(transform), mesh(mesh), material(material){}

Material* Object::GetMaterial() const {
    return material;
}

Mesh* Object::GetMesh() const {
    return mesh;
}

Transform* Object::GetTransform() const {
    return transform;
}
