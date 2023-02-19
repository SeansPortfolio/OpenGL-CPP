#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "Shader.h"
#include "Texture.h"
#include "Model.h"

class ResourceLoader
{
public:

	static std::string ReadFileText(const char* path);

	static std::shared_ptr<Shader> LoadShader(const char* vertexPath, const char* fragmentPath);

	static std::shared_ptr<Texture> LoadTexture(const char* path);

	static std::shared_ptr<Model> LoadModel(const char* path);

};

