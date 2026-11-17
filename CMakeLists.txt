cmake_minimum_required(VERSION 3.28)

project(workshop_setup_check)

option(BUILD_WITH_EASY_PROFILER "Enables dependencies to easy_profiler and utils based on that" OFF)

if(BUILD_WITH_EASY_PROFILER)
  add_compile_definitions(BUILD_WITH_EASY_PROFILER)
endif()

option(USE_BOOST_LIBRARIES "Enables dependencies to boost and examples using boost" OFF)

if(USE_BOOST_LIBRARIES)
  add_compile_definitions(USE_BOOST_LIBRARIES)
endif()

include(cmake/ExternalDependencies.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(easy_profiler_with_copy INTERFACE)

if(BUILD_WITH_EASY_PROFILER)
  add_custom_target(copy_easy_profiler
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:easy_profiler> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    DEPENDS easy_profiler
  )

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
