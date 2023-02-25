#pragma once

#include "Component.h"
#include "Transform.h"
#include "Model.h"
#include "Material.h"

#include <memory>

class ModelRenderer : public Component
{
public:

	std::shared_ptr<Model> Mesh;

	std::shared_ptr<Material> Material;

	void OnRender(glm::mat4 model, glm::mat4 view, glm::mat4 projection) override;

private:


};

