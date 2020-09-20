#pragma once

#include "Core.h"

namespace GameEngine {

	class GE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// will be implemented on client application
	Application* CreateApplication();

}