#pragma once

#include "Model.h"
#include "Shader.h"
#include "Texture.h"

class Material
{
public:

	std::shared_ptr<Shader> Shader;

	std::shared_ptr<Texture> Texture;

	virtual void Draw(glm::mat4 model, glm::mat4 view, glm::mat4 projection);

private:




};

