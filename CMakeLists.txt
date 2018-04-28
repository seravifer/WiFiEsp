set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 3.0)

project(WiFiEsp)

add_subdirectory(src)
add_subdirectory(src/util)