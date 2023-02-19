#include "Shader.h"

Shader::Shader()
{

}

bool Shader::Validate(GLint shaderID, GLint shaderType)
{
    GLint success = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);

        glDeleteShader(shaderID);

        printf(infoLog.data());

        switch (shaderType)
        {
        case GL_VERTEX_SHADER:
            printf("Failed to create vertex shader.");
            break;
        case GL_FRAGMENT_SHADER:
            printf("Failed to create fragment shader.");
            break;
        case GL_GEOMETRY_SHADER:
            printf("Failed to create geometry shader.");
            break;
        default:
            printf("Failed to link program.");
            break;
        }

        return false;
    }

    return true;
}


bool Shader::Create(const std::string& vertexSource, const std::string& fragmentSource)
{
    GLuint vertex, fragment;

    // vertex shader
    const char* source = vertexSource.c_str();

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &source, NULL);
    glCompileShader(vertex);

    if (!Validate(vertex, GL_VERTEX_SHADER))
    {
        return false;
    }

    // fragment Shader
    source = fragmentSource.c_str();

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &source, NULL);
    glCompileShader(fragment);

    if (!Validate(fragment, GL_FRAGMENT_SHADER))
    {
        return false;
    }

    // shader Program
    ShaderID = glCreateProgram();
    glAttachShader(ShaderID, vertex);
    glAttachShader(ShaderID, fragment);
    glLinkProgram(ShaderID);

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return true;
}

void Shader::Bind() const
{
    glUseProgram(ShaderID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::SetInt(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(ShaderID, name.c_str()), value);
}

void Shader::SetIntArray(const std::string& name, int* values, uint32_t count)
{
    
}

void Shader::SetFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(ShaderID, name.c_str()), value);
}

void Shader::SetMat4(const std::string& name, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}
