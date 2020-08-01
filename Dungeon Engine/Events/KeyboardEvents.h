#pragma once
#include "Event.h"
#include "KeyCodes.h"

class KeyEvent : public Event
{
public:
	KeyCode GetKeyCode() const { return _keyCode; }

protected:
	KeyEvent(KeyCode keyCode)
		:_keyCode(keyCode)
	{
	}
	
	KeyCode _keyCode;

};


class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(KeyCode keycode)
		:KeyEvent(keycode)
	{}

	virtual std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent : " << _keyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMove)

};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(KeyCode keyCode	)
		:KeyEvent(keyCode)
	{}

	virtual std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyrReleasedEvent : " << _keyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)

};

