#include <deque>
#include <format>
#include <iostream>
#include <string>
#include <thread>

#include <profiled_print.h>

#ifdef BUILD_WITH_EASY_PROFILER
#include "profiling_guard.h"
#endif

std::deque<std::string> wrapArguments(int argc, char **argv) { return {argv, argv + argc}; }

int main(int argc, char **argv) {
#ifdef BUILD_WITH_EASY_PROFILER
  ProfilingGuard _{"empty_project_with_main", "profs"};
#endif
  auto args = wrapArguments(argc, argv);

  std::size_t count = 0;
  for (const auto &arg : args) {
    ++count;
    print("Arg[{}]: {}", count, arg);
  }
  return 0;
}
