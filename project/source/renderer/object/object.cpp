#include "renderer/object.h"
#include "renderer/transform.h"

using namespace Renderer;

Object::Object(Mesh* mesh, Material* material)
 : mesh(mesh), material(material){
    transform = new Transform{};
}

Object::~Object(){
    delete transform;
}

Material* Object::GetMaterial() const {
    return material;
}

Mesh* Object::GetMesh() const {
    return mesh;
}

Transform* Object::GetTransform() const {
    return transform;
}
