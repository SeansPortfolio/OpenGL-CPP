#pragma once

#include "Component.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Camera : public Component
{
public:

	glm::mat4 GetLookAt();

	glm::mat4 GetProjection(float screenWidth, float screenHeight);

private:



};

