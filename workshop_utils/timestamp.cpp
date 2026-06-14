#include "timestamp.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <time.h>

std::string get_timestamp() {
  auto now = std::chrono::system_clock::now();
  auto epoch = now.time_since_epoch();

  const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
  std::ostringstream out;
#if 0
  // INFO This version is considered by Microsoft as better than standard one
  std::tm tm;
  localtime_s(&tm, &t_c);

  out << std::put_time(&tm, "%F_%H-%M-%S");
#else
  out << std::put_time(std::localtime(&t_c), "%F_%H-%M-%S");
#endif
  return out.str();
}

std::string get_log_timestamp() {
  auto now = std::chrono::system_clock::now();
  auto epoch = now.time_since_epoch();

  const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

  std::ostringstream out;
  out << std::put_time(std::localtime(&t_c), "%F %T.") << std::setfill('0') << std::setw(6)
      << (std::chrono::floor<std::chrono::microseconds>(epoch)
          - std::chrono::duration_cast<std::chrono::seconds>(epoch))
             .count();
  return out.str();
}
