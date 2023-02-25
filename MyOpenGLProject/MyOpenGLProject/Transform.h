#pragma once

#include "Component.h"

class Transform : public Component
{
public:

	glm::vec3 Position;

	glm::vec3 Rotation;

	glm::vec3 Scale;

	glm::mat4 GetModelMatrix();


private:




};

