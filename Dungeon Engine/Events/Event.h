#pragma once

#include <sstream>

enum class EventType
{
	KeyPressed, 
	KeyRelease,
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMove,
	WindowResize
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

class Event
{
public:
	virtual ~Event() = default;
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual bool IsHandled() const { return _handled; }
	virtual std::string ToString() const = 0;
	bool _handled;
		
private:
	EventType _type;

};

class EventDispatcher
{
public:
	EventDispatcher(Event& e)
		:_event(e)
	{}

	template<typename T, typename F>
	bool Dispatch(const F& func)
	{
		if (_event.GetEventType() == T::GetStaticType())
		{
			_event._handled	= func(static_cast<T&>(_event));
			return true;
		}
		return false;
	}

private:
	Event& _event;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.ToString();
}