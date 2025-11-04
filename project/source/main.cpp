#include "glad/glad.h"
#include "renderer/material.h"
#include "renderer/mesh.h"
#include "renderer/mesh_constructor.h"
#include "renderer/object.h"
#include "renderer/renderer.h"
#include "renderer/shader.h"
#include "renderer/texture.h"
#include "renderer/transform.h"
#include "utils/input.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


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

    Utils::Input::Init(window);

    glViewport(0, 0, mode->width, mode->height);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

    //this enables alpha values in png inages and color data
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    Renderer::Shader shader{"./shaders/standard_vertex.glsl", "./shaders/standard_fragment.glsl"};
    Renderer::Mesh* mesh = Renderer::MeshConstructor::Cube();
    Renderer::Texture texture{"./assets/dog.jpeg"};

    Renderer::Material material{&texture, &shader};

    Renderer::Object object{mesh, &material};
    Renderer::Object object2{mesh, &material};
    Renderer::Object object3{mesh, &material};
    
    object2.GetTransform()->SetPosition(-5.0f, 0.3f, -5.0f);
    object3.GetTransform()->SetPosition(5.0f, 0.3f, -7.0f);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(Utils::Input::GetKey(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, true);

        //test movement input
        if(Utils::Input::GetKey(GLFW_KEY_W))
            object.GetTransform()->SetPosition(0, 0, -0.1f);

        if(Utils::Input::GetKey(GLFW_KEY_S))
            object.GetTransform()->SetPosition(0, 0, 0.1f);

        if(Utils::Input::GetKey(GLFW_KEY_A))
            object.GetTransform()->SetPosition(-0.1f, 0, 0);

        if(Utils::Input::GetKey(GLFW_KEY_D))
            object.GetTransform()->SetPosition(0.1f, 0, 0);
        //rendering commands
        object.GetTransform()->SetRotation(0.0f, 0.1f, 0.1f);

        object2.GetTransform()->SetRotation(-2.0f, 0.3f, 0.1f);
        object3.GetTransform()->SetRotation(-1.5f, 0.7f, 0.4f);

        Renderer::Renderer::Draw(object);
        Renderer::Renderer::Draw(object2);
        Renderer::Renderer::Draw(object3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shader.Delete();
    delete mesh;
    texture.Delete();

    glfwTerminate();
}
