#include "renderer/shader.h"

#include "glm/gtc/type_ptr.hpp"
#include "utils/color.h"
#include "utils/error.h"
#include "utils/file.h"
#include "glad/glad.h"

#include <iostream>

using namespace Renderer;
using namespace std;
using namespace Utils;

Shader::Shader(string vertexPath, string fragmentPath){
    //read files
    std::string vertexOutput;
    std::string fragmentOutput;

    //error checking...
    LoadFile(vertexPath, &vertexOutput);
    LoadFile(fragmentPath, &fragmentOutput);

    CompileShaderSource(vertexOutput, &vertexShader, GL_VERTEX_SHADER);
    CompileShaderSource(fragmentOutput, &fragmentShader, GL_FRAGMENT_SHADER);
     
    LinkShaderProgram();

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

Shader::~Shader(){
    Delete();
}

void Shader::Use(){
    glUseProgram(shader);
}

void Shader::Delete(){
     if(deleted)
         return;

    glDeleteProgram(shader);
    deleted = true;
}

void Shader::SetUniformMatrix(std::string name, glm::mat4 matrix){
   unsigned int uniformLocation = glGetUniformLocation(shader, name.c_str()); 
   glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::CompileShaderSource
    (const std::string& source, ShaderID* id, unsigned int shaderType){
    *id = glCreateShader(shaderType);
    const char* csource = source.c_str();

    glShaderSource(*id, 1, &csource, NULL);
    glCompileShader(*id);

    int success;
    char infoLog[512];
    glGetShaderiv(*id, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(*id, 512, NULL, infoLog);
        Errors::DisplayError("Shader Compilation Error", Utils::YELLOW, infoLog);
    }
}

void Shader::LinkShaderProgram(){
    //linking shaders
    shader = glCreateProgram();

    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);

    int success;
    char infoLog[512];
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader, 512, NULL, infoLog);
        Errors::DisplayError("Shader Linking Error", Utils::YELLOW, infoLog);
    }
}
