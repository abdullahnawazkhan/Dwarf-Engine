#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace GameEngine {

	class GE_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

#define GE_CORE_ERROR(...)       ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_WARN(...)        ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_INFO(...)        ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_TRACE(...)       ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_CRITICAL(...)    ::GameEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define GE_CLIENT_ERROR(...)     ::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_CLIENT_WARN(...)      ::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_CLIENT_INFO(...)      ::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_CLIENT_TRACE(...)     ::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_CLIENT_CRITICAL(...)  ::GameEngine::Log::GetClientLogger()->critical(__VA_ARGS__)