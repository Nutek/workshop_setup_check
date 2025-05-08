cmake_minimum_required(VERSION 3.28)

find_package(Boost REQUIRED COMPONENTS core format test)

add_library(workshop_utils STATIC)
target_sources(workshop_utils
  PRIVATE
  blabber.cpp
  scope_print.cpp
  splitter.cpp
)
target_include_directories(workshop_utils
  PUBLIC
  includes
)
target_link_libraries(workshop_utils
  PUBLIC
  Boost::core
  Boost::format
)
target_compile_features(workshop_utils
  PUBLIC
  cxx_std_17
)

add_executable(test_workshop_utils)
target_sources(test_workshop_utils
  PRIVATE
  test_workshop_utils_main.cpp
  test_blabber.cpp
  test_type_info.cpp
)

target_link_libraries(test_workshop_utils
  PRIVATE
  workshop_utils
  Boost::unit_test_framework
  GTest::gmock
)