#include <iostream>

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Dwarf {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1289, 730);
		GE_CORE_TRACE(e);

		while (true);
	}

}