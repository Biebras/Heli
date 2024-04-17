#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define VERTEX_SHADER 0
#define FRAGMENT_SHADER 1

class Shader
{
public:
    unsigned int ID;
    
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char* shaderPath)
    {
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream shaderFile;

        // ensure ifstream objects can throw exceptions:
        shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        try 
        {
           bool result = ParseShaderFile(shaderPath);

           if(result == false)
               return;

           vertexCode = shaderCode[VERTEX_SHADER].str();
           fragmentCode = shaderCode[FRAGMENT_SHADER].str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }

        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();

        // 2. compile shaders
        unsigned int vertex, fragment;

        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");

        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");

        // shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);

        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }
    // activate the shader
    // ------------------------------------------------------------------------
    void Use() 
    { 
        glUseProgram(ID); 
    }

    // utility uniform functions
    // ------------------------------------------------------------------------
    void SetBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
    }

    // ------------------------------------------------------------------------
    void SetInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
    }

    // ------------------------------------------------------------------------
    void SetFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
    }

    // ------------------------------------------------------------------------
    void GetFloat(const std::string &name, float *value) const
    { 
        glGetUniformfv(ID, glGetUniformLocation(ID, name.c_str()), value); 
    }

    // ------------------------------------------------------------------------
    void SetMatrix4(const std::string &name, const glm::mat4 value) const
    { 
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

    // ------------------------------------------------------------------------
    void SetVector2(const std::string &name, float x, float y) const
    { 
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(glm::vec2(x, y)));
    }

    // ------------------------------------------------------------------------
    void SetVector2(const std::string &name, glm::vec2 value) const
    { 
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
    }

    // ------------------------------------------------------------------------
    void SetVector3(const std::string &name, float x, float y, float z) const
    { 
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(glm::vec3(x, y, z)));
    }

    // ------------------------------------------------------------------------
    void SetVector3(const std::string &name, glm::vec3 value) const
    { 
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
    }

private:

    std::stringstream shaderCode[2];

    bool ParseShaderFile(const std::string& shaderPath) 
    {
        std::ifstream shaderFile(shaderPath);

        if (!shaderFile.is_open())
        {
            std::cout << "Couldn't open shader file at" << shaderPath << std::endl;
            return false;
        }

        std::string line;
        int shaderType = -1; // 0 for vertex shader, 1 for fragment shader

        while (getline(shaderFile, line)) 
        {
            if (line.find("#shader") != std::string::npos) 
            {
                if (line.find("vertex") != std::string::npos)
                    shaderType = VERTEX_SHADER;
                else if (line.find("fragment") != std::string::npos)
                    shaderType = FRAGMENT_SHADER;
            } 
            else if (shaderType != -1) 
            {
                shaderCode[shaderType] << line << '\n';
            }
        }

        return true;
    }
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];

        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);

            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};
#endif
