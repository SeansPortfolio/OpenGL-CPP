#include "Renderer.h"

#include "../Dependencies/stb_image/stb_image.h"

bool Renderer::Init()
{
	glewExperimental = GL_TRUE;
	auto success = glewInit();

	if (success != GLEW_OK)
	{
		auto error = glewGetErrorString(success);
		printf("%s\n", error);

		return false;
	}

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);

	stbi_set_flip_vertically_on_load(true);
}

void Renderer::Quit()
{

}

void Renderer::SetViewport(float x, float y, float width, float height)
{
	glViewport(x, y, width, height);
}

void Renderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
