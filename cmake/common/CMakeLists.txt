cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME "example")
project (${PROJECT_NAME})



# All warnings we have
set (warning_flags "-Wall -Wextra")

# Use ISO C/C++
set (warning_flags "${warning_flags} -pedantic")

# Warn when local variable shadows global
set (warning_flags "${warning_flags} -Wshadow")

# Warn about conversions
set (warning_flags "${warning_flags} -Wconversion")

# Warn comparing floating numbers
set (warning_flags "${warning_flags} -Wfloat-equal")

# Warn when switch has no default case
set (warning_flags "${warning_flags} -Wswitch-default")

# Warn double initializing
set (warning_flags "${warning_flags} -Winit-self")

# Ignore system headers issues
set (warning_flags "${warning_flags} -Wno-system-headers")


# Use pretty output for Clang messages
set (clang_flags "-fcolor-diagnostics")


set (CMAKE_C_COMPILER clang)
set (CMAKE_CXX_COMPILER clang++)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${clang_flags}")

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${warning_flags}")


file (GLOB_RECURSE source_files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp")

add_executable (${PROJECT_NAME} ${source_files})
