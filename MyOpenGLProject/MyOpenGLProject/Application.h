#pragma once

#include "Renderer.h"
#include "Window.h"
#include "EventManager.h"
#include "ResourceLoader.h"
#include "SceneManager.h"

#include "Entity.h"
#include "Camera.h"


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <functional>

class Application
{
public:

	bool Init();

	void Run();

	void Quit();

private:

	void OnWindowClose(QuitEvent& eve);

	bool m_isRunning;

	Window window;

	Renderer renderer;

	EventManager eventManager;

	SceneManager sceneManager;

	std::shared_ptr<Shader> shader;

	std::shared_ptr<Texture> texture;

	std::shared_ptr<Model> model;

};

