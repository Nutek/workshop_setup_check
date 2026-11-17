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

if(BUILD_WITH_EASY_PROFILER)
  FetchContent_Declare(EasyProfiler
    GIT_REPOSITORY https://github.com/yse/easy_profiler.git
    GIT_TAG cc0e154635e5433344c4fb4fe940939a05465701 # develop after update of CMake
    SOURCE_DIR ${THIRDPARTY_SOURCE_DIR}/easy_profiler
    OVERRIDE_FIND_PACKAGE
    EXCLUDE_FROM_ALL
  )
  list(APPEND Dependencies EasyProfiler)
endif()

if(USE_BOOST_LIBRARIES)
  set(BOOST_INCLUDE_LIBRARIES core format range algorithm)

  FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.7z
    URL_MD5 5b8e7be1a6454fef772423800c98674d
    DOWNLOAD_EXTRACT_TIMESTAMP ON
    SOURCE_DIR ${THIRDPARTY_SOURCE_DIR}/boost
    OVERRIDE_FIND_PACKAGE
    EXCLUDE_FROM_ALL
  )

  list(APPEND Dependencies Boost)
endif()

FetchContent_MakeAvailable(
  ${Dependencies}
)

if(USE_BOOST_LIBRARIES)
  FetchContent_GetProperties(Boost)
endif()
