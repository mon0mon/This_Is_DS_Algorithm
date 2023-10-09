cmake_minimum_required(VERSION 3.16)
project(This_Is_DS_Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(02-04-Calculator Main_Calculator.c Calculator.h Calculator.c ../03-LinkedListStack/LinkedListStack.h ../03-LinkedListStack/LinkedListStack.c)