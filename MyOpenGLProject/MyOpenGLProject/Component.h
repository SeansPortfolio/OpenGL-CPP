#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Component
{
public:

	virtual void OnUpdate(float dt);

	virtual void OnRender(glm::mat4 model, glm::mat4 view, glm::mat4 projection);

private:

	

};

