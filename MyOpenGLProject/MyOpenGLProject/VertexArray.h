#pragma once

#include <vector>
#include <memory>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
public:

	VertexArray();

	void Bind();

	void Unbind();

	void AddVertexBuffer(std::vector<float> vertices);

	void AddIndexBuffer(std::vector<unsigned int> indices);

	void AddAttribute(unsigned int index, unsigned int size, unsigned int stride, unsigned int offset);

	void Draw();

private:

	unsigned int VAO;

	unsigned int IndexCount;

	std::shared_ptr<VertexBuffer> vertexBuffer;

	std::shared_ptr<IndexBuffer> indexBuffer;

};

