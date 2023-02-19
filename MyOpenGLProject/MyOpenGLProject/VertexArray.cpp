#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &VAO);
	IndexCount = 0;
}

void VertexArray::Bind()
{
	glBindVertexArray(VAO);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::AddVertexBuffer(std::vector<float> vertices)
{
	vertexBuffer = std::make_shared<VertexBuffer>();
	vertexBuffer->Bind();
	vertexBuffer->Create(vertices);
}

void VertexArray::AddIndexBuffer(std::vector<unsigned int> indices)
{
	indexBuffer = std::make_shared<IndexBuffer>();
	indexBuffer->Bind();
	indexBuffer->Create(indices);

	IndexCount = indices.size();
}

void VertexArray::AddAttribute(unsigned int index, unsigned int size, unsigned int stride, unsigned int offset)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
	glEnableVertexAttribArray(index);
}

void VertexArray::Draw()
{
	glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_INT, 0);
}
