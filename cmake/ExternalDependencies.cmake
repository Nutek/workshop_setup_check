cmake_minimum_required(VERSION 3.28)

include(FetchContent)

set(THIRDPARTY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/_deps)

FetchContent_Declare(GoogleTest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850
  SOURCE_DIR ${THIRDPARTY_SOURCE_DIR}/googletest
  OVERRIDE_FIND_PACKAGE
  EXCLUDE_FROM_ALL
)

FetchContent_MakeAvailable(
  GoogleTest
)
