#include "SceneManager.h"

std::shared_ptr<Entity> SceneManager::GetSceneRoot()
{
	if (SceneRoot == nullptr)
	{
		SceneRoot = std::make_shared<Entity>();
	}

	return SceneRoot;
}

void SceneManager::TickScene(float dt)
{
	if (SceneRoot == nullptr)
	{
		return;
	}

	SceneRoot->OnUpdate(dt);
}

void SceneManager::RenderScene(std::shared_ptr<Camera> camera, float screenWidth, float screenHeight)
{
	if (SceneRoot == nullptr)
	{
		return;
	}

	SceneRoot->OnRender(glm::mat4(1.0f), camera->GetLookAt(), camera->GetProjection(screenWidth, screenHeight));
}
