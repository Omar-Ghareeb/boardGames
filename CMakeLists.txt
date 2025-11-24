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
    games/SUS/SUS_Board.cpp
    games/SUS/SUS_Board.h
    games/SUS/SUS_UI.cpp
    games/SUS/SUS_UI.h
    games/Word_XO/Word_Board.cpp
    games/Word_XO/Word_Board.h
    games/Word_XO/Word_UI.h
    games/Word_XO/Word_UI.cpp
    games/memory_XO/memory_XO_board.cpp
    games/memory_XO/memory_XO_board.h
    games/memory_XO/memory_XO_UI.cpp
    games/memory_XO/memory_XO_UI.h
    games/Numerical_XO/Numerical_Board.cpp
    games/Numerical_XO/Numerical_Board.h
    games/Numerical_XO/Numerical_UI.cpp
    games/Numerical_XO/Numerical_UI.h
    games/4x4_XO/4x4_XO_Board.cpp
    games/4x4_XO/4x4_XO_Board.h
    games/4x4_XO/4x4_XO_UI.cpp
    games/4x4_XO/4x4_XO_UI.h
    )
file(COPY dic.txt DESTINATION ${CMAKE_BINARY_DIR})
