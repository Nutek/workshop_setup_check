#ifndef RANGE_UTILS_H_
#define RANGE_UTILS_H_

#include <ranges>

template <typename UInt>
auto irange(UInt end) {
  return std::views::iota(UInt{0}, end);
}

#endif // RANGE_UTILS_H_
