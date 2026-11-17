#include <deque>
#include <format>
#include <iostream>
#include <string>
#include <thread>

#include <profiled_print.h>
#include <profiling_guard.h>

std::deque<std::string> wrapArguments(int argc, char** argv) { return {argv, argv + argc}; }

int main(int argc, char** argv) {
  ProfilingGuard _{"empty_project_with_main", "profs"};
  auto args = wrapArguments(argc, argv);

  std::size_t count = 0;
  for (const auto& arg : args) {
    ++count;
    print("Arg[{}]: {}", count, arg);
  }
  return 0;
}
