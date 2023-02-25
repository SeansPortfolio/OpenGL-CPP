#include "Entity.h"

Entity::Entity()
{
	transform = AddComponent<Transform>();

	transform->Position = glm::vec3(0, 0, 0);
	transform->Rotation = glm::vec3(45, 45, 0);
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

void Entity::OnRender(glm::mat4 view, glm::mat4 projection)
{
	for (auto component : Components)
	{
		component->OnRender(transform->GetModelMatrix(), view, projection);
	}

	for (auto entity : Children)
	{
		entity->OnRender(view, projection);
	}
}

void Entity::AddChild(std::shared_ptr<Entity> child)
{
	Children.push_back(child);
}
