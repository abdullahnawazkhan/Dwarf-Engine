-- Main Workspace which includes both our Engine and Sandbox testing
workspace "GameEngine"
	architecture "x64"

	-- Debug:   everything enabled
	-- Release: optimization turned on and some debug features off
	-- Dist:    Final Distribution
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Game Engine Project
project "GameEngine"
	-- will be stored inside a folder "GameEngine" inside the workspace
	location "GameEngine"
	-- SharedLib is a DLL Project
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GE_PLATFORM_WINDOWS",
			"GE_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GE_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"GameEngine/vendor/spdlog/include",
		"GameEngine/src"
	}

	-- linking GameEngine with SandBox
	links {
		"GameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GE_DIST"
		optimize "On"