#ifndef TIME_UTILS_H_
#define TIME_UTILS_H_

#include <chrono>

template <typename TimePoint>
std::size_t get_milliseconds(TimePoint start, TimePoint stop) {
  using namespace std::chrono;
  return duration_cast<milliseconds>(stop - start).count();
}

#endif  // TIME_UTILS_H_
