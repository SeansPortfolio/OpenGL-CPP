#include "ModelRenderer.h"

void ModelRenderer::OnRender(glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	Material->Draw(model, view, projection);
	Mesh->Draw();
}
