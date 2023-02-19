#pragma once

#include "VertexArray.h"

#include <glm.hpp>

class Model
{
public:

	void Create(std::shared_ptr<VertexArray> vertexArray);

	void Create(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs, std::vector<unsigned int> indices);

	void Draw();

private:

	std::shared_ptr<VertexArray> ModelData;

};

