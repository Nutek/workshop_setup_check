#ifndef SCOPE_PRINT_H
#define SCOPE_PRINT_H

#include <string>

#include "class_mobility.hpp"

class ScopePrint : notmoveable, notcopyable {
public:
  ScopePrint(const std::string &msg);
  ~ScopePrint();

private:
  static void print_split(const char *prefix, const std::string &value);
  const std::string msg;
};

#endif // SCOPE_PRINT_H
