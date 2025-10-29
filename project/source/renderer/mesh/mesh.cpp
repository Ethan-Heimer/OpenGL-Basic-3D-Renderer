#include "renderer/mesh.h"
#include "glad/glad.h"
#include <vector>
#include <iostream>

using namespace Renderer;

Mesh::Mesh
    (float* verticies, size_t vert_size, 
     unsigned int* indicies, size_t indicies_size,
     float* uv_coords, size_t uv_size){ 

    //merge verticies and uv into single buffer
    std::vector<float> data{};

    //hard coded :/ jank ass system but ist whatever
    const int verticiesDepth = 3;
    const int uvDepth = 2;

    //calculate iteration count
    size_t verticiesCount = vert_size/sizeof(float);
    int pointCount = verticiesCount/verticiesDepth;

    //merge data
    for(int i = 0; i < pointCount; i++){
        //add vertex point into buffer
        for(int j = 0; j < verticiesDepth; j++)
            data.push_back(verticies[i * verticiesDepth + j]);

        //add uv point into buffer
        for(int j = 0; j < uvDepth; j++)
           data.push_back(uv_coords[i * uvDepth + j]); 
    }

    int dataSize = data.size() * sizeof(float);

    //vertex array object buffer- cache mesh's VBO and EBO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //Vertex Buffer Object - store vertex data
    glGenBuffers(1, &VBO);

    //Element Buffer Object - store indicies
    glGenBuffers(1, &EBO);

    //copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data.data(), GL_STATIC_DRAW);
 
    //copy our indicies in a buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies_size, indicies, GL_STATIC_DRAW);

    //generate vertex attrib pointer
    //vertex point
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //uv point
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

Mesh::~Mesh(){
    Delete();
}

void Mesh::Delete(){
    if(deleted)
        return;

    deleted = true;

    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glDeleteVertexArrays(1, &VAO);
}

void Mesh::Use(){
    glBindVertexArray(VAO);
}
