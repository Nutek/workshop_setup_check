#ifndef SPLITTER_H
#define SPLITTER_H

#include <ostream>
#include <string>

std::string string_splitter(const std::string &msg);
void print_splitter(const std::string &msg);

template <typename StreamType>
void print_splitter(StreamType &out, const std::string &msg) {
  out << string_splitter(msg) << std::endl;
}

#endif // SPLITTER_H
