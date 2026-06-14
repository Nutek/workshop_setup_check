#include "splitter.h"

#include <format>
#include <iostream>
#include <string>

std::string string_splitter(const std::string &msg) { return std::format(">>> {:=<80}", msg + ' '); }

void print_splitter(const std::string &msg) { print_splitter(std::cout, msg); }
