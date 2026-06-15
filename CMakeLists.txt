cmake_minimum_required(VERSION 3.28)

project(workshop_setup_check)


option(BUILD_WITH_PROFILING "Enables dependencies to easy_profiler and utils based on that" OFF)

include(cmake/ExternalDependencies.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

if(BUILD_WITH_PROFILING)
  add_custom_target(copy_easy_profiler
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:easy_profiler> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    DEPENDS easy_profiler
  )

  add_library(easy_profiler_with_copy INTERFACE)
  target_link_libraries(easy_profiler_with_copy
    INTERFACE
    easy_profiler
  )
  add_dependencies(easy_profiler_with_copy
    copy_easy_profiler
  )
endif()

include(cmake/AddUnitTestConfig.cmake)

add_subdirectory(workshop_utils)
add_subdirectory(threading_test)

# Others
add_subdirectory(empty_project_with_main)

add_subdirectory(empty_project_of_unit_test)
