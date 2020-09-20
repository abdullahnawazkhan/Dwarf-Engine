#pragma once

#include "Event.h"

#include <sstream>

namespace Dwarf {

	class D_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }
	
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::MouseMoved;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "MouseMoved";
		}

		int GetCategoryFlags() const override {
			return EventCategoryMouse | EventCategoryInput;
		}

	private:
		float mouseX;
		float mouseY;
	};

	class D_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(float xoffset, float yoffset)
			: XOffSet(xoffset), YOffSet(yoffset) {}

		inline float GetXOffSet() const { return XOffSet; }
		inline float GetYOffSet() const { return YOffSet; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffSet() << ", " << GetYOffSet();
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::MouseScrolled;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "MouseScrolled";
		}

		int GetCategoryFlags() const override {
			return EventCategoryMouse | EventCategoryInput;
		}

	private:
		float XOffSet;
		float YOffSet;
	};

	class D_API MouseButtonEvent : public Event {
	public:
		inline int GetButton() const { return button; }

		int GetCategoryFlags() const override {
			return EventCategoryMouseButton | EventCategoryInput;
		}

	protected:
		MouseButtonEvent(int button)
			: button(button) {}

		int button;
	};

	class D_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::MouseButtonPressed;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "MousePressed";
		}
	};

	class D_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::MouseButtonReleased;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "MouseReleased";
		}
	};

}