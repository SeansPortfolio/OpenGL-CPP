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

    m_isRunning = true;
	return true;
}

void Application::Run()
{
    renderer.SetViewport(0, 0, window.Width, window.Height);
    renderer.SetClearColor(0.3, 0.4, 0.8, 1.0);

    auto cubeEntity = std::make_unique<Entity>();
    auto cubeMesh = cubeEntity->AddComponent<ModelRenderer>();

    auto cubeMat = std::make_shared<Material>();
    cubeMat->Shader = ResourceLoader::LoadShader("Resources\\Shaders\\UnlitTexture.vert", "Resources\\Shaders\\UnlitTexture.frag");
    cubeMat->Texture = ResourceLoader::LoadTexture("Resources\\Textures\\CubeAtlas.png");
    cubeMesh->Mesh = ResourceLoader::LoadModel("Resources\\Models\\SimpleCube.obj");
    cubeMesh->Material = cubeMat;

    auto cameraEntity = std::make_unique<Entity>();
    auto camera = cameraEntity->AddComponent<Camera>();

	while (m_isRunning)
	{
        glm::mat4 viewMat = camera->GetLookAt();
        glm::mat4 projectionMat = camera->GetProjection((float)window.Width, (float)window.Height);

        renderer.Clear();

        cubeEntity->OnRender(viewMat, projectionMat);

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
