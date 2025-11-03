#include "renderer/mesh.h"
#include "glad/glad.h"
#include <vector>

using namespace Renderer;

Mesh::Mesh
    (float* verticies, size_t vert_size, 
     unsigned int* indicies, size_t indicies_size,
     float* uv_cords, size_t uv_size){ 

    vertCount = vert_size;
    indiciesCount = indicies_size;

    //merge verticies and uv into single buffer
    std::vector<float> data{};
    MergeBufferData(verticies, vert_size, uv_cords, uv_size, &data);
    CreateBuffers(&data, indicies, indicies_size);

    indicesDefined = true;

}

Mesh::Mesh(float* verticies, size_t vert_size,
           float* uv_cords, size_t uv_size){
    
    vertCount = vert_size;

    std::vector<float> data{};
    MergeBufferData(verticies, vert_size, uv_cords, uv_size, &data);
    CreateBuffers(&data);

    indicesDefined = false;
}

Mesh::~Mesh(){
    Delete();
}

int Mesh::GetVertCount() const{
    return vertCount;
}
int Mesh::GetIndiciesCount() const{
    return indiciesCount;
}

void Mesh::Delete(){
    if(deleted)
        return;

    deleted = true;

    glDeleteBuffers(1, &VBO);

    if(IsIndiciesDefiened())
        glDeleteBuffers(1, &EBO);

    glDeleteVertexArrays(1, &VAO);
}

void Mesh::Use(){
    glBindVertexArray(VAO);
}

bool Mesh::IsIndiciesDefiened() const {
    return indicesDefined;
}


void Mesh::MergeBufferData(float* verticies, size_t vert_size, 
                     float* uv_cords, size_t uv_size,
                     std::vector<float>* data){
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
            data->push_back(verticies[i * verticiesDepth + j]);

        //add uv point into buffer
        for(int j = 0; j < uvDepth; j++)
           data->push_back(uv_cords[i * uvDepth + j]); 
    }
}

void Mesh::CreateBuffers(const std::vector<float>* data, 
                   unsigned int* indicies, size_t indicies_size){

    CreateBuffers(data);

    glBindVertexArray(VAO);

    //Element Buffer Object - store indicies
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies_size, indicies, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::CreateBuffers(const std::vector<float>* data){
    int dataSize = data->size() * sizeof(float);

    //vertex array object buffer- cache mesh's VBO and EBO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //Vertex Buffer Object - store vertex data
    glGenBuffers(1, &VBO);


    //copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data->data(), GL_STATIC_DRAW);
 
    //generate vertex attrib pointer
    //vertex point
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //uv point
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

