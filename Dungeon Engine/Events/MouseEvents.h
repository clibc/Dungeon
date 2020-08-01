#pragma once

#include "Event.h"
#include "MouseCodes.h"

class MouseButtonEvent : Event
{
public:
	MouseCode GetMouseButton() const { return _mouseCode; }

protected:
	
	MouseButtonEvent(MouseCode mouseCode)
		:_mouseCode(mouseCode)
	{}
	
	MouseCode _mouseCode;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(MouseCode mouseCode)
		:MouseButtonEvent(mouseCode)
	{}

	virtual std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent" << _mouseCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
	MouseButtonReleasedEvent(MouseCode mouseCode)
		:MouseButtonEvent(mouseCode)
	{
	}

	virtual std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent" << _mouseCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonReleased)

};

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(float posX, float posY)
		:_posX(posX), _posY(posY)
	{
	}

	inline float GetX() { return _posX; }
	inline float GetY() { return _posY; }
	
	virtual std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent" << _posX << " , " <<  _posY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMove)
	
private: 
	float _posX;
	float _posY;

};
