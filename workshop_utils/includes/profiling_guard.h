#ifndef PROFILING_GUARD_H_
#define PROFILING_GUARD_H_

#include <filesystem>
#include <string>
#include <string_view>

class ProfilingGuard {
 public:
  ProfilingGuard(std::string_view prefix,
                 std::filesystem::path output_directory = std::filesystem::current_path());
  ~ProfilingGuard();

 private:
  std::string prefix{};
  std::filesystem::path output_directory;
};

#endif  // PROFILING_GUARD_H_