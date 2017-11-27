cmake_minimum_required(VERSION 3.8)
project(Lab1_OS)

set(CMAKE_C_STANDARD 11)

#include_directories(${ROOT_SOURCE_DIR})
#FILE(GLOB MyCSources *.c)
#ADD_EXECUTABLE(MyExecutable ${MyCSources} manager.c manager.h)
FILE(GLOB MyCSources *.c *.h test.txt)
include_directories(${CMAKE_SOURCE_DIR})
ADD_EXECUTABLE(MyExecutable ${MyCSources})
#set(SOURCE_FILES main.c)
#add_executable(Lab1_OS ${SOURCE_FILES})