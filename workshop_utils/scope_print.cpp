#include <iostream>

#include "class_mobility.hpp"
#include "scope_print.h"
#include "splitter.h"

namespace {
const char *SPLITTER_BEGIN = "BEGIN: ";
const char *SPLITTER_END = "END  : ";
} // namespace

ScopePrint::ScopePrint(const std::string &msg) : msg{msg} {
  print_split(SPLITTER_BEGIN, msg);
}

ScopePrint::~ScopePrint() { print_split(SPLITTER_END, msg); }

void ScopePrint::print_split(const char *prefix, const std::string &value) {
  print_splitter(std::cout, prefix + value);
}
