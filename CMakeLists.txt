cmake_minimum_required(VERSION 3.28)

project(workshop_setup_check)

include(cmake/ExternalDependencies.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if (NOT MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

include(cmake/AddUnitTestConfig.cmake)

add_subdirectory(workshop_utils)
