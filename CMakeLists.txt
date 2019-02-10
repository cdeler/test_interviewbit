CMAKE_MINIMUM_REQUIRED(VERSION 3.13)
PROJECT(test_01 C)

SET(CMAKE_C_STANDARD 11)

ADD_LIBRARY(test test.h test_01 test_02 test_04.c test_05.c test_06.c test_07.c)

ADD_EXECUTABLE(test_binary main)
TARGET_LINK_LIBRARIES(test_binary test)