#include "Material.h"

void Material::Draw(glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	Texture->Bind(1);

	Shader->SetMat4("Model", model);
	Shader->SetMat4("View", view);
	Shader->SetMat4("Projection", projection);

	Shader->Bind();
}
