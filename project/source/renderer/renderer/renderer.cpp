#include "renderer/object.h"
#include "renderer/renderer.h"

#include "glad/glad.h"


void Renderer::Renderer::Draw(const Object& object){ 
        Mesh* mesh = object.GetMesh();
        Material* material = object.GetMaterial();
        Shader* shader = material->GetShader();

        //projection
        glm::mat4 view = glm::mat4{1.f};
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f); 

        mesh->Use();
        material->Use();

        shader->SetUniformMatrix("transform", object.GetTransform()->GetTransformationMatrix());
        shader->SetUniformMatrix("view", view);
        shader->SetUniformMatrix("projection", projection);

        int elementCount = 0;

        if(mesh->IsIndiciesDefiened()){
            elementCount = mesh->GetIndiciesCount();
            glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, 0);
        }
        else{
            elementCount = mesh->GetVertCount();
            glDrawArrays(GL_TRIANGLES, 0, elementCount);
        }

        glBindVertexArray(0);
}
