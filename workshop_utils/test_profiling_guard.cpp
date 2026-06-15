#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <chrono>
#include <thread>

#include <easy/profiler.h>

#include "profiling_guard.h"

using namespace std::chrono_literals;

TEST(ProfilingGuardShould, dropSomeFile) {
  ProfilingGuard guard{"some_prefix"};
  EASY_BLOCK("Testing guard");
  std::this_thread::sleep_for(200ms);
  EASY_END_BLOCK;
}
