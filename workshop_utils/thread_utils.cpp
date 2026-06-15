#include <iomanip>
#include <sstream>
#include <thread>

#include "thread_utils.h"

std::string get_thread_id_str() {
  std::ostringstream out;
  out << "0x" << std::hex << std::this_thread::get_id();
  return out.str();
}
