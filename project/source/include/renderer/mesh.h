#ifndef MESH_H
#define MESH_H

#include <cstdlib>
#include <cwchar>
#include <vector>

namespace Renderer{    
    using VertexBufferObject = unsigned int;
    using ElementBufferObject = unsigned int; 
    using VertexArrayObject = unsigned int;

    class Mesh{
        public:
            Mesh(float* verticies, size_t vert_size, 
                unsigned int* indicies, size_t indicies_size,
                float* uv_cords, size_t uv_size);

            Mesh(float* verticies, size_t vert_size,
                float* uv_cords, size_t uv_size);

            ~Mesh();

            int GetVertCount() const;
            int GetIndiciesCount() const;

            void Use();
            void Delete();

            bool IsIndiciesDefiened() const;

        private:
           VertexArrayObject VAO; 
           VertexBufferObject VBO;
           ElementBufferObject EBO;

           int vertCount = 0;
           int indiciesCount = 0;

           bool deleted = false;
           bool indicesDefined = false;

           void CreateBuffers(const std::vector<float>* data);
           void CreateBuffers(const std::vector<float>* data, 
                   unsigned int* indicies, size_t indicies_size);

           void MergeBufferData(float* verticies, size_t vert_size, 
                                float* uv_cords, size_t uv_size,
                                std::vector<float>* data);
    };
}

#endif
