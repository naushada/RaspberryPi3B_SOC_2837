cmake_minimum_required(VERSION 3.16.3)
project(gpio)
find_package(GTest REQUIRED)


include_directories(../inc)
include_directories(test)

#Adding Complier flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -g -Wall -Wextra")

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp"  
                    "../src/gpio.cpp")

enable_testing()

add_executable(gpio_test ${SOURCES})
target_link_libraries(gpio_test gtest_main)

target_link_libraries(gpio_test gtest)
target_link_libraries(gpio_test pthread)

add_test(gpio_gtests gpio_test)
gtest_discover_tests(gpio_test)
