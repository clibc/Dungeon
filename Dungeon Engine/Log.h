#pragma once
#include <memory>
#include "spdlog/spdlog.h"

#define DG_ENGINE_DEBUG(...)       Log::GetLogger()->debug(__VA_ARGS__)
#define DG_ENGINE_INFO(...)        Log::GetLogger()->info(__VA_ARGS__)
#define DG_ENGINE_WARN(...)        Log::GetLogger()->warn(__VA_ARGS__)
#define DG_ENGINE_TRACE(...)       Log::GetLogger()->trace(__VA_ARGS__)
#define DG_ENGINE_ERROR(...)       Log::GetLogger()->error(__VA_ARGS__)
#define DG_ENGINE_CRITICAL(...)    Log::GetLogger()->critical(__VA_ARGS__)

class Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetLogger() { return _logger; }


private:
	static std::shared_ptr<spdlog::logger> _logger;
};


