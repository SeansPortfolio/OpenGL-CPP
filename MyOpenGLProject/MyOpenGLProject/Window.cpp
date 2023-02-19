#include "Window.h"

bool Window::Init()
{
    if (!glfwInit())
    {
        return false;
    }

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwSetWindowUserPointer(window, this);
    glfwMakeContextCurrent(window);
    glfwGetWindowSize(window, &Width, &Height);
    
    glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
    {
        QuitEvent eve;
        eve.Type = EventType::QuitEvent;
        EventManager::FireEvent(eve);
    });

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);

        auto windowObj = (Window*)glfwGetWindowUserPointer(window);

        windowObj->Width = width;
        windowObj->Height = height;

        WindowEvent eve;
        eve.Type = EventType::ResizeEvent;
        eve.Width = width;
        eve.Height = height;

        EventManager::FireEvent(eve);
    });

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        auto windowObj = (Window*)glfwGetWindowUserPointer(window);

        KeyEvent eve;
        eve.KeyCode = key;

        if (action == GLFW_PRESS)
        {
            eve.Type = EventType::KeyDownEvent;
        }
        if (action == GLFW_RELEASE)
        {
            eve.Type = EventType::KeyUpEvent;
        }

        EventManager::FireEvent(eve);
    });

    return true;
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::Quit()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}