cmake_minimum_required(VERSION 3.28)

find_package(GoogleTest REQUIRED)

add_library(workshop_utils STATIC)
target_sources(workshop_utils
  PUBLIC
  ./includes/blabber.h
  ./includes/scope_print.h
  ./includes/splitter.h
  ./includes/timestamp.h
  ./includes/range_utils.h

  PRIVATE
  ./blabber.cpp
  ./scope_print.cpp
  ./splitter.cpp
  ./timestamp.cpp
)

target_include_directories(workshop_utils
  PUBLIC
  includes
)
target_compile_features(workshop_utils
  PUBLIC
  cxx_std_20
)

add_unit_test(test_workshop_utils
  test_type_info.cpp
  test_blabber.cpp
  test_timestamp.cpp
)

target_link_libraries(test_workshop_utils
  PRIVATE
  workshop_utils
)
