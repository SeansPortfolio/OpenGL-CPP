#pragma once

#include <vector>
#include <GL/glew.h>

class VertexBuffer
{
public:

	VertexBuffer();

	void Bind();

	void Unbind();

	void Create(std::vector<float> vertices);

private:

	unsigned int VBO;

};

