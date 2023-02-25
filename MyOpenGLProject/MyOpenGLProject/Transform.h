#pragma once

#include "Component.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Transform : public Component
{
public:

	glm::vec3 Position;

	glm::vec3 Rotation;

	glm::vec3 Scale;

private:




};

