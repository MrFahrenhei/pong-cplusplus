cmake_minimum_required(VERSION 3.29)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(raylib REQUIRED)

include_directories(Core)

add_executable(game
    main.cpp
        Ball.cpp
        Ball.h
        Paddle.cpp
        Paddle.h
        CpuPaddle.cpp
        CpuPaddle.h)
target_link_libraries(game raylib)