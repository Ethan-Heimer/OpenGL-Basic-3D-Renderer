#include "renderer/camera.h"
#include "renderer/object.h"
#include "renderer/renderer.h"

#include "glad/glad.h"


void Renderer::Renderer::Draw(const Object& object, const Camera& camera){ 
        Mesh* mesh = object.GetMesh();
        Material* material = object.GetMaterial();
        Shader* shader = material->GetShader();

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(90.0f), 800.0f / 600.0f, 0.1f, 100.0f); 

        mesh->Use();
        material->Use();

        shader->SetUniformMatrix("transform", object.GetTransform()->GetTransformationMatrix());
        shader->SetUniformMatrix("view", camera.GetViewMatrix());
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
