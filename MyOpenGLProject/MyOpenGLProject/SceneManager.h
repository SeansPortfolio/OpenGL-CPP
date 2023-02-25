#pragma once

#include "Entity.h"

#include <vector>
#include <memory>

class SceneManager
{
public:

	std::shared_ptr<Entity> CreateEntity();

	std::shared_ptr<Entity> GetSceneRoot();

private:

	std::shared_ptr<Entity> SceneRoot;


};

