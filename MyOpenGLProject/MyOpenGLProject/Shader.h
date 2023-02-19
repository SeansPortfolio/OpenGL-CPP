#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <glm.hpp>

#define GLEW_STATIC
#include <GL/glew.h>

class Shader
{
public:

	Shader();

	// Inherited via Shader
	bool Create(const std::string& vertexSource, const std::string& fragmentSource);

	void Bind() const;
	void Unbind() const;

	void SetInt(const std::string& name, int value);
	void SetIntArray(const std::string& name, int* values, uint32_t count);
	void SetFloat(const std::string& name, float value);
	void SetMat4(const std::string& name, glm::mat4 value);

private:

	static bool Validate(GLint shaderID, GLint shaderType);

	int ShaderID;




};

