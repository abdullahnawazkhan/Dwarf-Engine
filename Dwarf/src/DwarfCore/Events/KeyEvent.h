#pragma once

#include "Event.h"

#include <sstream>

namespace Dwarf {

	class D_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return keyCode; }

		int GetCategoryFlags() const override {
			return EventCategoryKeyboard | EventCategoryInput;
		}
	protected:
		KeyEvent(int keycode) 
			: keyCode(keycode) {}

		int keyCode;
	};

	class D_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatcount)
			: KeyEvent(keycode), repeatCount(repeatcount) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::KeyPressed;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "KeyPressed";
		}
	private:
		int repeatCount;
	};

	class D_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::KeyReleased;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "KeyReleased";
		}
	};

}