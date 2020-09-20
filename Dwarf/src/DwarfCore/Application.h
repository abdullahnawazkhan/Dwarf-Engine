#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Dwarf {

	class D_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// will be implemented on client application
	Application* CreateApplication();

}