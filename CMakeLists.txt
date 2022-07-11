cmake_minimum_required(VERSION 3.22)
project(bd)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)
set(SOURCES main.cpp src/hash_table.hpp src/primes.h)

add_executable(bd main.cpp)
