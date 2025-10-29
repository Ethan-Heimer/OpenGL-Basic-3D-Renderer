#ifndef SHADER_H
#define SHADER_H

#include <string>
using ShaderID = unsigned int;
using ProgramID = unsigned int;

namespace Renderer{
    class Shader{
        public:
            Shader(std::string vertexShaderPath, std::string fragmentShaderPath);

            void Use();

        private:
            ShaderID fragmentShader;
            ShaderID vertexShader;

            ProgramID shader;

            void CompileShaderSource(const std::string& source, ShaderID* id, unsigned int shaderType);
            void LinkShaderProgram();
    };
}

#endif
