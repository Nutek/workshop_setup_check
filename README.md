# Workshop Setup Check

## How to use this repository

- Repository is managed by CMake; version 3.28 required
- Consider usage of [Ninja](https://github.com/ninja-build/ninja/releases)
- Required compiler with C++17 support

## Build & run

1. Configure project

   ```sh
   cmake -G Ninja
      -DCMAKE_MAKE_PROGRAM=<path to Ninja>
      -DCMAKE_C_COMPILER=<path to C compiler>
      -DCMAKE_CXX_COMPILER=<path to C++ compiler>
      -S <path to project source dir>
      -B <path to project build dir>
   ```

2. Build project
   
   ```sh
   cmake --build <path to project build dir>
   ```
3. Run all tests

   ```sh
   ctest --test-dir <path to project build dir>
   ```

## Trouble shooting

1. If application is compiled, but it stops without any output in console
   1. Check if all shared libraries are visible from PATH or LD_LIBRARY perspective
      1. Like libc++.dll
   2. E.g. on Windows: call unit test application from file explorer
      1. Popup windows appears in case of missing library
2. Project Configures slowly
   1. That's natural - it downloads dependencies from internet.
   2. Please be patient
3. My compiler does not support `-static` flag
   1. Comment out line from main `CMakeLists.txt` file
      1. `# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")`
