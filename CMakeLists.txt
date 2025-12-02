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
    games/Pyramid_XO/Pyramid_Board.cpp
    games/Pyramid_XO/Pyramid_Board.h
    games/Pyramid_XO/Pyramid_UI.cpp
    games/Pyramid_XO/Pyramid_UI.h
        games/Obstacles_Tic-Tac-Toe/Obstacles_Board.cpp
        games/Obstacles_Tic-Tac-Toe/Obstacles_Board.h
        games/Obstacles_Tic-Tac-Toe/Obstacles_UI.cpp
        games/Obstacles_Tic-Tac-Toe/Obstacles_UI.h
        games/Four_in_a_row/Four_in_a_row_Board.cpp
        games/Four_in_a_row/Four_in_a_row_Board.h
        games/Four_in_a_row/Four_in_a_row_UI.cpp
        games/Four_in_a_row/Four_in_a_row_UI.h
        games/5X5-tic-tac-toe/5X5_Board.cpp
        games/5X5-tic-tac-toe/5X5_Board.h
        games/5X5-tic-tac-toe/5X5_UI.cpp
        games/5X5-tic-tac-toe/5X5_UI.h
        games/Misere/Misere_Board.cpp
        games/Misere/Misere_Board.h
        games/Misere/Misere_UI.h
        games/Misere/Misere_UI.cpp
        games/Diamond/Diamond_Board.cpp
        games/Diamond/Diamond_Board.h
        games/Diamond/Diamond_UI.h
        games/Diamond/Diamond_UI.cpp
        games/Ultimate/Ultimate_Board.cpp
        games/Ultimate/Ultimate_Board.h
        games/Ultimate/Ultimate_UI.cpp
        games/Ultimate/Ultimate_UI.h
    )
file(COPY dic.txt DESTINATION ${CMAKE_BINARY_DIR})
