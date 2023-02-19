#include "EventManager.h"

using QuitCallback = std::function<void(QuitEvent&)>;
std::vector<QuitCallback> EventManager::QuitCallbacks;

using WindowCallback = std::function<void(WindowEvent&)>;
std::vector<WindowCallback> EventManager::WindowCallbacks;

using KeyCallback = std::function<void(KeyEvent&)>;
std::vector<KeyCallback> EventManager::KeyCallbacks;

void EventManager::AddQuitEventHandler(QuitCallback callback)
{
	QuitCallbacks.push_back(callback);
}

void EventManager::RemoveQuitEventHandler(QuitCallback callback)
{
	
}

void EventManager::AddWindowEventHandler(WindowCallback callback)
{
	WindowCallbacks.push_back(callback);
}

void EventManager::RemoveWindowEventHandler(WindowCallback callback)
{

}

void EventManager::AddKeyEventHandler(KeyCallback callback)
{
	KeyCallbacks.push_back(callback);
}

void EventManager::RemoveKeyEventHandler(KeyCallback callback)
{
}

void EventManager::FireEvent(Event& eve)
{
	if (eve.Type == EventType::QuitEvent)
	{
		for (auto callback : QuitCallbacks)
		{
			auto quitEvent = (QuitEvent)eve;
			callback(quitEvent);
		}
	}

	if (eve.Type == EventType::ResizeEvent)
	{
		for (auto callback : WindowCallbacks)
		{
			auto windowEvent = (WindowEvent)eve;
			callback(windowEvent);
		}
	}

	if (eve.Type == EventType::KeyUpEvent || eve.Type == EventType::KeyDownEvent)
	{
		for (auto callback : KeyCallbacks)
		{
			auto keyEvent = (KeyEvent)eve;
			callback(keyEvent);
		}
	}
}
