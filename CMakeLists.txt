cmake_minimum_required(VERSION 3.29)
project(boared_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(board_games
    BoardGame_Classes.h
    gameMenu.h
    gameMenu.cpp
    games/Infinity_XO/Infinity_Board.cpp
    games/Infinity_XO/Infinity_Board.h
    games/Infinity_XO/Infinity_UI.cpp
    games/Infinity_XO/Infinity_UI.h
    )
