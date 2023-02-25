#include "Application.h"

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

bool Application::Init()
{
    m_isRunning = false;

    if (!window.Init())
    {
        return false;
    }
    
    if (!renderer.Init())
    {
        return false;
    }

    EventManager::AddQuitEventHandler(BIND_EVENT_FN(Application::OnWindowClose));

    shader = ResourceLoader::LoadShader("Resources\\Shaders\\UnlitTexture.vert", "Resources\\Shaders\\UnlitTexture.frag");
    texture = ResourceLoader::LoadTexture("Resources\\Textures\\CubeAtlas.png");
    model = ResourceLoader::LoadModel("Resources\\Models\\SimpleCube.obj");

    m_isRunning = true;
	return true;
}

void Application::Run()
{
    renderer.SetViewport(0, 0, window.Width, window.Height);
    renderer.SetClearColor(0.3, 0.4, 0.8, 1.0);

    auto cubeEntity = std::make_unique<Entity>();

    auto cameraEntity = std::make_unique<Entity>();
    auto camera = cameraEntity->AddComponent<Camera>();

	while (m_isRunning)
	{
        glm::mat4 modelMat = glm::mat4(1.0f);
        glm::mat4 viewMat = camera->GetLookAt();
        glm::mat4 projectionMat = camera->GetProjection((float)window.Width, (float)window.Height);

        renderer.Clear();

        shader->Bind();
        texture->Bind(1);

        shader->SetMat4("Model", modelMat);
        shader->SetMat4("View", viewMat);
        shader->SetMat4("Projection", projectionMat);

        model->Draw();
        shader->Unbind();

        window.SwapBuffers();
        window.PollEvents();
	}
}

void Application::Quit()
{
    window.Quit();
    renderer.Quit();

    m_isRunning = false;
}


void Application::OnWindowClose(QuitEvent& eve)
{
    m_isRunning = false;
}
