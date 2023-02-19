#pragma once

#include <vector>
#include <GL/glew.h>

class IndexBuffer
{
public:

	IndexBuffer();

	void Create(std::vector<unsigned int> indices);

	void Bind();

	void Unbind();

private:

	unsigned int EBO;

};

