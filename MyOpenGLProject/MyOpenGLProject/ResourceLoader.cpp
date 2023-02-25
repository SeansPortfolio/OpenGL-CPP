#include "ResourceLoader.h"

#define STB_IMAGE_IMPLEMENTATION    
#include "../Dependencies/stb_image/stb_image.h"

std::string ResourceLoader::ReadFileText(const char* path)
{
	std::ifstream file(path);
	std::string fullText;

	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			fullText += line + "\n";
		}
	}

	file.close();
	return fullText;
}

std::shared_ptr<Shader> ResourceLoader::LoadShader(const char* vertexPath, const char* fragmentPath)
{
	auto shader = std::make_shared<Shader>();
	auto vertexSource = ReadFileText(vertexPath);
	auto fragmentSource = ReadFileText(fragmentPath);

	if (shader->Create(vertexSource, fragmentSource))
	{
		return shader;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<Texture> ResourceLoader::LoadTexture(const char* path)
{
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

	auto texture = std::make_shared<Texture>();
	texture->Create(width, height, nrChannels, data);
	stbi_image_free(data);

	return texture;
}

std::shared_ptr<Model> ResourceLoader::LoadModel(const char* path)
{
	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;

	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

	int pos = -1;

	std::ifstream file(path);
	if (file.is_open())
	{
		std::string line;

		while (!file.eof())
		{
			file >> line;

			if (line == "v")
			{
				glm::vec3 vertex;
				file >> vertex.x;
				file >> vertex.y;
				file >> vertex.z;
				temp_vertices.push_back(vertex);
			}

			else if (line == "vt")
			{
				glm::vec2 uv;
				file >> uv.x;
				file >> uv.y;
				temp_uvs.push_back(uv);
			}
			else if (line == "vn")
			{
				glm::vec3 normal;
				file >> normal.x;
				file >> normal.y;
				file >> normal.z;
				temp_normals.push_back(normal);
			}
			else if (line == "f")
			{
				std::string vertex1, vertex2, vertex3;
				char filler;

				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				for (int i = 0; i < 3; i++)
				{
					file >> vertexIndex[i];
					file >> filler;
					file >> uvIndex[i];
					file >> filler;
					file >> normalIndex[i];
				}

				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);

				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);

				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
		}
	}

	file.close();

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<unsigned int> indices;

	// For each vertex of each triangle
	for (unsigned int i = 0; i < vertexIndices.size(); i++) {

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normalIndex = normalIndices[i];

		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[vertexIndex - 1];
		glm::vec2 uv = temp_uvs[uvIndex - 1];
		glm::vec3 normal = temp_normals[normalIndex - 1];

		// Put the attributes in buffers
		vertices.push_back(vertex);
		normals.push_back(normal);
		uvs.push_back(uv);
		indices.push_back(i);
	}

	auto model = std::make_shared<Model>();
	model->Create(vertices, normals, uvs, indices);
	return model;
}
