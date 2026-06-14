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

FetchContent_MakeAvailable(
  GoogleTest
)
