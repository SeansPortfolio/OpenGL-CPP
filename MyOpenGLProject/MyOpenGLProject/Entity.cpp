#include "Entity.h"

Entity::Entity()
{
	transform = AddComponent<Transform>();

	transform->Position = glm::vec3(0, 0, 0);
	transform->Rotation = glm::vec3(0, 0, 0);
	transform->Scale = glm::vec3(1, 1, 1);
}

void Entity::OnUpdate(float dt)
{
	for (auto component : Components)
	{
		component->OnUpdate(dt);
	}

	for (auto entity : Children)
	{
		entity->OnUpdate(dt);
	}
}

void Entity::OnRender(glm::mat4 parentModel, glm::mat4 view, glm::mat4 projection)
{
	auto globalModelMatrix = parentModel * transform->GetModelMatrix();

	for (auto component : Components)
	{
		component->OnRender(globalModelMatrix, view, projection);
	}

	for (auto entity : Children)
	{
		entity->OnRender(globalModelMatrix, view, projection);
	}
}

void Entity::AddChild(std::shared_ptr<Entity> child)
{
	Children.push_back(child);
}
