cmake_minimum_required(VERSION 3.16)
project(Snake)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "-lncurses ${SDL2_LIBRARIES}")
add_executable(Snake main.cpp Board.cpp Board.h Snake.cpp Snake.h Direction.h Apple.cpp Apple.h BodyPart.cpp BodyPart.h SoundController.cpp SoundController.h Sound.h)