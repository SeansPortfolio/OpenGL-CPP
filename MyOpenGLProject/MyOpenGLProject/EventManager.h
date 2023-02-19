#pragma once

#include "Event.h"

#include <vector>
#include <functional>

class EventManager
{
public:

	using QuitCallback = std::function<void(QuitEvent&)>;
	using WindowCallback = std::function<void(WindowEvent&)>;
	using KeyCallback = std::function<void(KeyEvent&)>;

	static void AddQuitEventHandler(QuitCallback callback);

	static void RemoveQuitEventHandler(QuitCallback callback);

	static void AddWindowEventHandler(WindowCallback callback);

	static void RemoveWindowEventHandler(WindowCallback callback);

	static void AddKeyEventHandler(KeyCallback callback);

	static void RemoveKeyEventHandler(KeyCallback callback);

	static void FireEvent(Event& eve);

private:

	static std::vector<QuitCallback> QuitCallbacks;

	static std::vector<WindowCallback> WindowCallbacks;

	static std::vector<KeyCallback> KeyCallbacks;

};

