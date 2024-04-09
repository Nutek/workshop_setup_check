cmake_minimum_required(VERSION 3.28)

find_package(Boost REQUIRED)

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

add_unit_test(test_workshop_utils
  test_type_info.cpp
  test_blabber.cpp
)
target_link_libraries(test_workshop_utils
PRIVATE
  workshop_utils
)