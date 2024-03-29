#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define D_API __declspec(dllexport)
	#else
		#define D_API __declspec(dllimport)
	#endif
#else
	#error Game Engine Only Supports Windows
#endif

#define BIT(x) (1 << x)