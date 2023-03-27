cmake_minimum_required(VERSION 3.21)
project(SmartCalc)

set(CMAKE_C_STANDARD 11)

add_executable(calculator parserToReversePolish.c findResult.c optional.c)
