#pragma once

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

class Renderer
{
public:

	bool Init();

	void Quit();

	void SetViewport(float x, float y, float width, float height);

	void SetClearColor(float r, float g, float b, float a);

	void Clear();

};

