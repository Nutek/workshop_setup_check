#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "timestamp.h"

using namespace ::testing;

TEST(Timestamp, playground) {
  std::cout << get_timestamp() << std::endl;
  std::cout << get_log_timestamp() << std::endl;
}
