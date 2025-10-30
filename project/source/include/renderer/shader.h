#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
using ShaderID = unsigned int;
using ProgramID = unsigned int;

namespace Renderer{
    class Shader{
        public:
            Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
            ~Shader();

            void Use();
            void Delete();

            void SetUniformMatrix(std::string name, glm::mat4 matrix);

        private:
            ShaderID fragmentShader;
            ShaderID vertexShader;

            ProgramID shader;

            bool deleted = false;

            void CompileShaderSource(const std::string& source, ShaderID* id, unsigned int shaderType);
            void LinkShaderProgram();
    };
}

#endif
