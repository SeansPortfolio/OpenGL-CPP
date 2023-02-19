#include "Model.h"

void Model::Create(std::shared_ptr<VertexArray> vertexArray)
{
	ModelData = vertexArray;
}

void Model::Create(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs, std::vector<unsigned int> indices)
{
	std::vector<float> formattedVertices;

	for (size_t i = 0; i < vertices.size(); i++)
	{
		formattedVertices.push_back(vertices[i].x);
		formattedVertices.push_back(vertices[i].y);
		formattedVertices.push_back(vertices[i].z);

		//formattedVertices.push_back(normals[i].x);
		//formattedVertices.push_back(normals[i].y);
		//formattedVertices.push_back(normals[i].z);

		formattedVertices.push_back(uvs[i].x);
		formattedVertices.push_back(uvs[i].y);
	}

	std::shared_ptr<VertexArray> vertexArray = std::make_shared<VertexArray>();

	vertexArray->Bind();
	vertexArray->AddVertexBuffer(formattedVertices);
	vertexArray->AddIndexBuffer(indices);

	vertexArray->AddAttribute(0, 3, 5 * sizeof(float), 0); // Vertex positions
	vertexArray->AddAttribute(1, 2, 5 * sizeof(float), 3 * sizeof(float)); // UVs

	ModelData = vertexArray;
}

void Model::Draw()
{
	ModelData->Bind();
	ModelData->Draw();
	ModelData->Unbind();
}
