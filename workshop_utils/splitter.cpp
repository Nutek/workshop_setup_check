#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>

#include <boost/format.hpp>
#include <boost/format/group.hpp>

#include "splitter.h"

namespace {
constexpr char SPLITTER_CHARACTER = '=';

enum {
  SPLITTER_WIDTH = 80,
};
} // namespace

std::string string_splitter(const std::string &msg) {
  auto fmt = boost::format(">>> %-s") %
             boost::io::group(std::setfill(SPLITTER_CHARACTER),
                              std::setw(SPLITTER_WIDTH), msg + ' ');
  return fmt.str();
}

void print_splitter(const std::string &msg) { print_splitter(std::cout, msg); }
