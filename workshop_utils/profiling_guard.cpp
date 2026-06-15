#include "profiling_guard.h"

#ifdef BUILD_WITH_PROFILING
#include <format>

#include <easy/profiler.h>

#include "timestamp.h"
#endif

ProfilingGuard::ProfilingGuard(std::string_view prefix, std::filesystem::path output_directory)
    : prefix{prefix}, output_directory{output_directory} {
#ifdef BUILD_WITH_PROFILING
  EASY_PROFILER_ENABLE;
#endif
}

ProfilingGuard::~ProfilingGuard() {
#ifdef BUILD_WITH_PROFILING
  if (!std::filesystem::is_directory(output_directory)) {
    std::filesystem::create_directory(output_directory);
  }
  auto output_path = output_directory / std::format("{}_{}.prof", prefix, get_timestamp());

  profiler::dumpBlocksToFile(output_path.string().c_str());
#endif
}
