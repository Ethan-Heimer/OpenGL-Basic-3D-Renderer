#include "glad/glad.h"
#include "renderer/material.h"
#include "renderer/mesh.h"
#include "renderer/object.h"
#include "renderer/shader.h"
#include "renderer/texture.h"
#include "renderer/transform.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

//mesh Data
float vertices[] = {
    0.0f, 0.5f, 0.0f, // top right
    0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
};

float uv[] = {
    0.0f, 0.0f,
    0.5f, 0.0f,
    0.5f, 1.0f
};

unsigned int indices[] = { // note that we start from 0!
    0, 1, 2, // first triangle
};

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "LearnOpenGL", monitor, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, mode->width, mode->height);
    glEnable(GL_BLEND);

    //this enables alpha values in png inages and color data
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    

    //when errors here - throws shader errors : does not terminate
    Renderer::Shader shader{"./shaders/standard_vertex.glsl", "./shaders/standard_fragment.glsl"};
    Renderer::Mesh mesh{vertices, sizeof(vertices), indices, sizeof(indices), uv, sizeof(uv)};
    Renderer::Texture texture{"./assets/dog.png"};

    Renderer::Material material{&texture, &shader};
    Renderer::Transform transform{};

    Renderer::Object object{&transform, &mesh, &material};

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);

        //rendering commands
        mesh.Use();
        material.Use();

        shader.SetUniformMatrix("transform", object.GetTransform()->GetTransformationMatrix());

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shader.Delete();
    mesh.Delete();
    texture.Delete();

    glfwTerminate();
}
