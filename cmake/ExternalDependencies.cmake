cmake_minimum_required(VERSION 3.28)

include(FetchContent)

set(THIRDPARTY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/_deps)

FetchContent_Declare(GoogleTest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723
  SOURCE_DIR ${THIRDPARTY_SOURCE_DIR}/googletest
  OVERRIDE_FIND_PACKAGE
  EXCLUDE_FROM_ALL
)
list(APPEND Dependencies GoogleTest)

if(BUILD_WITH_PROFILING)
  FetchContent_Declare(EasyProfiler
    GIT_REPOSITORY https://github.com/yse/easy_profiler.git
    GIT_TAG cc0e154635e5433344c4fb4fe940939a05465701 # develop after update of CMake
    SOURCE_DIR ${THIRDPARTY_SOURCE_DIR}/easy_profiler
    OVERRIDE_FIND_PACKAGE
    EXCLUDE_FROM_ALL
  )
  list(APPEND Dependencies EasyProfiler)
endif()

FetchContent_MakeAvailable(
  ${Dependencies}
)
