#include "renderer/mesh.h"
#include "glad/glad.h"
#include <vector>

using namespace Renderer;

Mesh::Mesh
    (float* verticies, size_t vert_size, 
     unsigned int* indicies, size_t indicies_size,
     float* uv_coords, size_t uv_size){ 

    //vertex array object buffer- cache mesh's VBO and EBO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //Vertex Buffer Object - store vertex data
    glGenBuffers(1, &VBO);

    //Element Buffer Object - store indicies
    glGenBuffers(1, &EBO);

    //copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vert_size, verticies, GL_STATIC_DRAW);
 
    //copy our indicies in a buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies_size, indicies, GL_STATIC_DRAW);

    //generate vertex attrib pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

Mesh::~Mesh(){
    if(!deleted)
        Delete();
}

void Mesh::Delete(){
    deleted = true;

    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glDeleteVertexArrays(1, &VAO);
}

void Mesh::Use(){
    glBindVertexArray(VAO);
}
