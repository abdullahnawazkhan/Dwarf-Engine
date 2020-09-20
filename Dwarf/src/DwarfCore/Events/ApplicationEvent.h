#pragma once 

#include "Event.h"

#include <sstream>

namespace Dwarf {

	class D_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: width(width), height(height) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::WindowResize;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "WindowResized";
		}

		int GetCategoryFlags() const override {
			return EventCategoryApplication;
		}
	private:
		unsigned int width;
		unsigned int height;
	};

	class D_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		static EventType GetStaticEvent() {
			return EventType::WindowClose;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "WindowClose";
		}

		int GetCategoryFlags() const override {
			return EventCategoryApplication;
		}
	};

	class D_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		static EventType GetStaticEvent() {
			return EventType::AppTick;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "AppTick";
		}

		int GetCategoryFlags() const override {
			return EventCategoryApplication;
		}
	};

	class D_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		static EventType GetStaticEvent() {
			return EventType::AppUpdate;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "AppUpdate";
		}

		int GetCategoryFlags() const override {
			return EventCategoryApplication;
		}
	};

	class D_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		static EventType GetStaticEvent() {
			return EventType::AppRender;
		}

		EventType GetEventType() const override {
			return GetStaticEvent();
		}

		const char* GetName() const override {
			return "AppRender";
		}

		int GetCategoryFlags() const override {
			return EventCategoryApplication;
		}
	};

}