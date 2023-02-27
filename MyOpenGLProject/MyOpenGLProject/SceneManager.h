#pragma once

#include "Entity.h"
#include "Camera.h"

#include <vector>
#include <memory>

class SceneManager
{
public:

	std::shared_ptr<Entity> GetSceneRoot();

	void TickScene(float dt);

	void RenderScene(std::shared_ptr<Camera> camera, float screenWidth, float screenHeight);

private:

	std::shared_ptr<Entity> SceneRoot;
};

