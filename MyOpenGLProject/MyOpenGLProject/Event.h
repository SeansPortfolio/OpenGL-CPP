#pragma once

enum class EventType
{
	None,

	QuitEvent,

	ResizeEvent,

	KeyUpEvent,
	KeyDownEvent,
};

class Event
{
public:
	EventType Type;


private:

};

class QuitEvent : public Event
{

};

class WindowEvent : public Event
{
public:

	int Width, Height;
};

class KeyEvent : public Event
{
public:
	int KeyCode;

};