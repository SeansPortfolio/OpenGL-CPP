#pragma once

#include <GLFW/glfw3.h>
#include <functional>
#include <iostream>

#include "EventManager.h"

class Window
{
public:

	bool Init();

	void SwapBuffers();

	void PollEvents();

	void Quit();

public:

	int Width, Height;

private:

	GLFWwindow* window;

}; 


