cmake_minimum_required(VERSION 3.21)
project(DZ30)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 21f42cf882d0b7e5ae9e3434574fc47e187728de) # The commit hash for 1.8.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_subdirectory(src)

target_link_libraries(DZ30 PRIVATE cpr::cpr)
