#pragma once

#ifndef HE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argz) {
	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

