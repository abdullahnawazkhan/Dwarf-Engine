#pragma once

#ifndef HE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argz) {
	GameEngine::Log::Init();
	
	GE_CORE_CRITICAL("This is a critical msg");
	GE_CORE_TRACE("This is a trace msg");
	GE_CORE_INFO("This is a info msg");
	GE_CORE_ERROR("This is a error msg");
	GE_CORE_WARN("This is a warn msg");

	GE_CLIENT_CRITICAL("This is a critical msg");
	GE_CLIENT_TRACE("This is a trace msg");
	GE_CLIENT_INFO("This is a info msg");
	GE_CLIENT_ERROR("This is a error msg");
	GE_CLIENT_WARN("This is a warn msg");


	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

