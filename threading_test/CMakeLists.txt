cmake_minimum_required(VERSION 3.28)

add_executable(threading_test)
target_sources(threading_test
PRIVATE
    threading_test.cpp
)
target_compile_features(threading_test
PRIVATE
    cxx_std_20
)

