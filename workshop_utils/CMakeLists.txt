cmake_minimum_required(VERSION 3.28)

find_package(GoogleTest REQUIRED)

if(BUILD_WITH_EASY_PROFILER)
  find_package(EasyProfiler REQUIRED)
endif()

add_library(workshop_utils STATIC)
target_sources(workshop_utils
  PUBLIC
  ./includes/blabber.h
  ./includes/scope_print.h
  ./includes/splitter.h
  ./includes/timestamp.h
  ./includes/profiling_guard.h
  ./includes/time_utils.h
  ./includes/range_utils.h

  PRIVATE
  ./blabber.cpp
  ./scope_print.cpp
  ./splitter.cpp
  ./timestamp.cpp
  ./thread_utils.cpp
)
if(BUILD_WITH_EASY_PROFILER)
  target_sources(workshop_utils
    PUBLIC
    ./includes/thread_utils.h
    ./includes/profiling_guard.h
    PRIVATE
    ./profiling_guard.cpp
  )
  target_compile_definitions(workshop_utils
    PUBLIC
    BUILD_WITH_EASY_PROFILER
  )
endif()

target_include_directories(workshop_utils
  PUBLIC
  includes
)
if(BUILD_WITH_EASY_PROFILER)
  target_link_libraries(workshop_utils
    PUBLIC
    easy_profiler_with_copy
  )
endif()

target_compile_features(workshop_utils
  PUBLIC
  cxx_std_20
)

add_unit_test(test_workshop_utils
  test_type_info.cpp
  test_blabber.cpp
  test_timestamp.cpp
)

if(BUILD_WITH_EASY_PROFILER)
  target_sources(test_workshop_utils
    PRIVATE
    test_profiling_guard.cpp
  )
endif()

target_link_libraries(test_workshop_utils
  PRIVATE
  workshop_utils
)
