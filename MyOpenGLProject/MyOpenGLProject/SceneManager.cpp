#include "SceneManager.h"

std::shared_ptr<Entity> SceneManager::CreateEntity()
{
	return std::shared_ptr<Entity>();
}

std::shared_ptr<Entity> SceneManager::GetSceneRoot()
{
	if (SceneRoot == nullptr)
	{
		SceneRoot = std::make_shared<Entity>();
	}

	return SceneRoot;
}
