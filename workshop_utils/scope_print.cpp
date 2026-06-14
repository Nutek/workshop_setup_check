#include "scope_print.h"

#include <iostream>

#include "splitter.h"

namespace {
const char *SPLITTER_BEGIN = "BEGIN: ";
const char *SPLITTER_END = "END  : ";
} // namespace

ScopePrint::ScopePrint(std::string_view msg) : msg{msg} { print_split(SPLITTER_BEGIN, this->msg); }

ScopePrint::~ScopePrint() { print_split(SPLITTER_END, msg); }

void ScopePrint::print_split(const char *prefix, const std::string &value) {
  print_splitter(std::cout, prefix + value);
}
