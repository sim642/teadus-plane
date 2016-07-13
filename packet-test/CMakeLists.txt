cmake_minimum_required(VERSION 3.5)
project(packet_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Packet.cpp Packet.hpp)
add_executable(packet_test ${SOURCE_FILES})