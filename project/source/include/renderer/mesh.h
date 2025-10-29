#ifndef MESH_H
#define MESH_H

#include <cstdlib>


namespace Renderer{    
    using VertexBufferObject = unsigned int;
    using ElementBufferObject = unsigned int; 
    using VertexArrayObject = unsigned int;

    class Mesh{
        public:
            Mesh(float* verticies, size_t vert_size, 
                unsigned int* indicies, size_t indicies_size,
                float* uv_cords, size_t uv_size);
            ~Mesh();

            void Use();
            void Delete();

        private:
           VertexArrayObject VAO; 
           VertexBufferObject VBO;
           ElementBufferObject EBO;

           bool deleted = false;
    };
}

#endif
