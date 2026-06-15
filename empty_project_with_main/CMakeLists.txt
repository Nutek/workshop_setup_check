cmake_minimum_required(VERSION 3.28)

project(empty_project_with_main)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
    workshop_utils
)
target_compile_features(${PROJECT_NAME}
    PRIVATE
    cxx_std_20
)
