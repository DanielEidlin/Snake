cmake_minimum_required(VERSION 3.16)
project(Snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lncurses")
add_executable(Snake main.cpp Board.cpp Board.h Snake.cpp Snake.h Direction.h Apple.cpp Apple.h BodyPart.cpp BodyPart.h)