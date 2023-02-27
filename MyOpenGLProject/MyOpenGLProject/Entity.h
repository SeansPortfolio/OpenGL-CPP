#pragma once



#include "Component.h"
#include "Transform.h"

#include <vector>
#include <memory>

class Entity
{
public:

	std::shared_ptr<Transform> transform;


public:

	Entity();

	void OnUpdate(float dt);

	void OnRender(glm::mat4 parentModel, glm::mat4 view, glm::mat4 projection);

	void AddChild(std::shared_ptr<Entity> child);

	template <class T>
	std::shared_ptr<T> AddComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Base");

		auto newComponent = std::make_shared<T>();
		Components.push_back(newComponent);
		return newComponent;
	}

private:

	std::vector<std::shared_ptr<Entity>> Children;

	std::vector<std::shared_ptr<Component>> Components;
};

