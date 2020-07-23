#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::_logger;

void Log::Init()
{
	spdlog::set_pattern("%^[%r:%t:%l]*[%n] *** [%v]%$");
	_logger = spdlog::stdout_color_mt("DUNGEON");
	_logger->set_level(spdlog::level::trace);
}