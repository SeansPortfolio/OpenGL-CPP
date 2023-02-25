#include "Entity.h"

Entity::Entity()
{
	transform = AddComponent<Transform>();
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

void Entity::OnRender()
{
	for (auto component : Components)
	{
		component->OnRender();
	}

	for (auto entity : Children)
	{
		entity->OnRender();
	}
}

void Entity::AddChild(std::shared_ptr<Entity> child)
{
	Children.push_back(child);
}
