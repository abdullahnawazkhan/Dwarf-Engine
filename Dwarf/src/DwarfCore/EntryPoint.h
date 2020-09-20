#pragma once

#ifndef HE_PLATFORM_WINDOWS

extern Dwarf::Application* Dwarf::CreateApplication();

int main(int argc, char** argz) {
	Dwarf::Log::Init();

	GE_CORE_WARN("This is a warn msg");
	GE_CLIENT_ERROR("This is a error msg");

	auto app = Dwarf::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

