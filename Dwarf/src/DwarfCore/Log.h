#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Dwarf {

	class D_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

#define GE_CORE_ERROR(...)       ::Dwarf::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_WARN(...)        ::Dwarf::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_INFO(...)        ::Dwarf::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_TRACE(...)       ::Dwarf::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_CRITICAL(...)    ::Dwarf::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define GE_CLIENT_ERROR(...)     ::Dwarf::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_CLIENT_WARN(...)      ::Dwarf::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_CLIENT_INFO(...)      ::Dwarf::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_CLIENT_TRACE(...)     ::Dwarf::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_CLIENT_CRITICAL(...)  ::Dwarf::Log::GetClientLogger()->critical(__VA_ARGS__)