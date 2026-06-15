#ifndef PROFILED_PRINT_H_
#define PROFILED_PRINT_H_

#include <format>
#include <iostream>

#if BUILD_WITH_PROFILING
#include <easy/profiler.h>
#endif

#include "thread_utils.h"

template <typename... Types>
void print(std::string_view fmt, Types &&...args) {
#if BUILD_WITH_PROFILING
  EASY_FUNCTION(profiler::colors::DarkGreen);
#endif

  std::cout << std::format("Thread: {} Msg: {}\n", get_thread_id_str(),
                           std::vformat(fmt, std::make_format_args(std::forward<Types>(args)...)));
}

#endif // PROFILED_PRINT_H_
