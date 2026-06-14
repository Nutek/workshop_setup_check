cmake_minimum_required(VERSION 3.28)

project(some_project)

add_unit_test(test_${PROJECT_NAME}
  test_someothing.cpp
)

target_compile_features(test_${PROJECT_NAME}
  PUBLIC
  cxx_std_20
)

# If you need to link with something
# target_link_libraries(test_${PROJECT_NAME}
# PRIVATE
# workshop_utils
# )