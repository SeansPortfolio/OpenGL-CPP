#include "Transform.h"

glm::mat4 Transform::GetModelMatrix()
{
	glm::mat4 matrix(1.0f);

	matrix = glm::translate(matrix, Position);
	matrix = glm::rotate(matrix, Rotation.x, glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, Rotation.y, glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, Rotation.z, glm::vec3(0, 0, 1));
	matrix = glm::scale(matrix, Scale);

	return matrix;
}
