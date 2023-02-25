#include "Camera.h"

glm::mat4 Camera::GetLookAt()
{
	return glm::lookAt(glm::vec3(0, 5, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

glm::mat4 Camera::GetProjection(float screenWidth, float screenHeight)
{
	return glm::perspective(glm::radians(60.0f), screenWidth / screenHeight, 0.1f, 1000.0f);
}
