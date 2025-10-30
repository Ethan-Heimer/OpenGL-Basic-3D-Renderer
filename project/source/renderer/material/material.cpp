#include "renderer/material.h"

using namespace Renderer;

Material::Material(Texture* texture, Shader* shader) : 
    texture(texture), shader(shader){}

void Material::Use(){
    texture->Use();
    shader->Use();
}


