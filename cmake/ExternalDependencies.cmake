cmake_minimum_required(VERSION 3.28)

include(FetchContent)

set(THIRDPARTY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/_deps)

FetchContent_Declare(GoogleTest
  GIT_REPOSITORY  https://github.com/google/googletest.git
  GIT_TAG         58d77fa8070e8cec2dc1ed015d66b454c8d78850
  SOURCE_DIR      ${THIRDPARTY_SOURCE_DIR}/googletest
  OVERRIDE_FIND_PACKAGE
  EXCLUDE_FROM_ALL
)

set(BOOST_INCLUDE_LIBRARIES core format)

FetchContent_Declare(
  Boost
  URL             https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.7z
  URL_MD5         5b8e7be1a6454fef772423800c98674d
  DOWNLOAD_EXTRACT_TIMESTAMP ON
  SOURCE_DIR      ${THIRDPARTY_SOURCE_DIR}/boost
  OVERRIDE_FIND_PACKAGE
  EXCLUDE_FROM_ALL
)


FetchContent_MakeAvailable(
  GoogleTest 
  Boost
)

FetchContent_GetProperties(Boost)
