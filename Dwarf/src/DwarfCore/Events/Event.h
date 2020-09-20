#pragma once

// add this in makefile
#include "../Core.h"

#include <string>
#include <functional>

namespace Dwarf {

	// buffer for events is still not implemented
	// each event will occue immediately

	// includes all types of events
	// their implementations are in their respected header files
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// this is used to filter some events and allow others
	// this is save it as a 5 bit value
	// 1 1 1 1 1 -> each bit representing a specific category
	// so to select some and filter others we can AND(&) a specific category with the bit sequence
	enum EventCategory {
		None = 0,
		EventCategoryApplication  = BIT(0),
		EventCategoryInput        = BIT(1),
		EventCategoryKeyboard     = BIT(2),
		EventCategoryMouse        = BIT(3),
		EventCategoryMouseButton  = BIT(4)
	};

	class D_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		// this will be used to filter out the EventCategories
		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool handled = false;
	};

	class EventDispacher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispacher(Event& e)
			: m_Event(e) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}

}