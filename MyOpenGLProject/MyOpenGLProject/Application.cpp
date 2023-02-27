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

    CreateScene();

	while (m_isRunning)
	{
        UpdateFrame(1 / 60.0f);
        RenderFrame();

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

void Application::CreateScene()
{
    renderer.SetViewport(0, 0, window.Width, window.Height);
    renderer.SetClearColor(0.3, 0.4, 0.8, 1.0);

    auto cubeEntity = std::make_shared<Entity>();
    auto cubeMesh = cubeEntity->AddComponent<ModelRenderer>();

    auto cubeMat = std::make_shared<Material>();
    cubeMat->Shader = ResourceLoader::LoadShader("Resources\\Shaders\\UnlitTexture.vert", "Resources\\Shaders\\UnlitTexture.frag");
    cubeMat->Texture = ResourceLoader::LoadTexture("Resources\\Textures\\CubeAtlas.png");
    cubeMesh->Mesh = ResourceLoader::LoadModel("Resources\\Models\\SimpleCube.obj");
    cubeMesh->Material = cubeMat;

    auto cubeEntity2 = std::make_shared<Entity>();
    cubeEntity2->transform->Position = glm::vec3(0, 2, 4);

    auto cubeMesh2 = cubeEntity2->AddComponent<ModelRenderer>();
    cubeMesh2->Mesh = ResourceLoader::LoadModel("Resources\\Models\\SimpleCube.obj");
    cubeMesh2->Material = cubeMat;

    auto cameraEntity = std::make_shared<Entity>();
    mainCamera = cameraEntity->AddComponent<Camera>();

    sceneManager.GetSceneRoot()->AddChild(cubeEntity);
    cubeEntity->AddChild(cubeEntity2);
    sceneManager.GetSceneRoot()->AddChild(cameraEntity);

    centerCube = cubeEntity;
}

void Application::UpdateFrame(float dt)
{
    centerCube->transform->Rotation.y += 1 * dt;

    sceneManager.TickScene(dt);
}

void Application::RenderFrame()
{
    renderer.Clear();
    sceneManager.RenderScene(mainCamera, window.Width, window.Height);
}

void Application::OnWindowClose(QuitEvent& eve)
{
    m_isRunning = false;
}
