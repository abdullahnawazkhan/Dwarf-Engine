#pragma once

#ifndef HE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argz) {
	GameEngine::Log::Init();

	GE_CORE_WARN("This is a warn msg");
	GE_CLIENT_ERROR("This is a error msg");

	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

