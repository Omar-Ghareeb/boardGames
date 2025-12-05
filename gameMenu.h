#pragma once
#include "games/Infinity_XO/Infinity_Board.h"
#include "games/Infinity_XO/Infinity_UI.h"

#include "games/Obstacles_Tic-Tac-Toe/Obstacles_UI.h"
#include "games/Obstacles_Tic-Tac-Toe/Obstacles_Board.h"

#include "games/SUS/SUS_Board.h"
#include "games/SUS/SUS_UI.h"

#include "games/Word_XO/Word_UI.h"
#include "games/Word_XO/Word_Board.h"

#include "games/memory_XO/memory_XO_board.h"
#include "games/memory_XO/memory_XO_UI.h"

#include "games/Numerical_XO/Numerical_Board.h"
#include "games/Numerical_XO/Numerical_UI.h"

#include "games/4x4_XO/4x4_XO_Board.h"
#include "games/4x4_XO/4x4_XO_UI.h"

#include "games/Pyramid_XO/Pyramid_Board.h"
#include "games/Pyramid_XO/Pyramid_UI.h"

#include "games/Four_in_a_row/Four_in_a_row_Board.h"
#include "games/Four_in_a_row/Four_in_a_row_UI.h"

#include "games/5X5-tic-tac-toe/5X5_Board.h"
#include "games/5X5-tic-tac-toe/5X5_UI.h"

#include "games/Misere/Misere_Board.h"
#include "games/Misere/Misere_UI.h"

#include "games/Diamond/Diamond_Board.h"
#include "games/Diamond/Diamond_UI.h"

#include "games/Ultimate/Ultimate_Board.h"
#include "games/Ultimate/Ultimate_UI.h"

using namespace std;

/**
 * @brief Helper function to clean up dynamically allocated memory.
 * @tparam T The data type used by the board and player (e.g., char, int).
 * @param ui Pointer to the UI object to delete.
 * @param board Pointer to the Board object to delete.
 * @param players Pointer to the array of Player pointers to delete.
 */
template <typename T>
void cleanMem(UI<T> *ui, Board<T> *board, Player<T> **players)
{
    delete board;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
    delete[] players;
    delete ui;
}

/**
 * @brief Instantiates and runs the Infinity Tic-Tac-Toe game.
 */
void runInfinity()
{
    UI<char> *game_ui = new Infinity_UI();
    Board<char> *Infinity_board = new infinity_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> Infinity_game(Infinity_board, players, game_ui);
    Infinity_game.run();
    cleanMem(game_ui, Infinity_board, players);
}

/**
 * @brief Instantiates and runs the Obstacles Tic-Tac-Toe game.
 */
void runInObstacles()
{
    UI<char> *game_ui = new Obstacles_UI();
    Board<char> *board = new Obstacles_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> Obstacles_game(board, players, game_ui);
    Obstacles_game.run();
    cleanMem(game_ui, board, players);
}

/**
 * @brief Instantiates and runs the Diamond Tic-Tac-Toe game.
 */
void runDiamond()
{
    UI<char> *game_ui = new Diamond_UI();
    Board<char> *board = new Diamond_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> Diamond_game(board, players, game_ui);
    Diamond_game.run();
    cleanMem(game_ui, board, players);
}

/**
 * @brief Instantiates and runs the Misere Tic-Tac-Toe game.
 * @details Includes specific logic to identify and display the loser,
 * as the goal in Misere is to avoid winning.
 */
void runMisere()
{
    Misere_Board *board = new Misere_Board();
    Misere_UI *game_ui = new Misere_UI(board);
    Player<char> **players = game_ui->setup_players();
    GameManager<char> Misere_game(board, players, game_ui);
    Misere_game.run();

    // Post-game logic specific to Misere
    Player<char> *loser = nullptr;
    for (int i = 0; i < 2; ++i)
    {
        if (board->is_lose(players[i]))
        {
            loser = players[i];
            break;
        }
    }
    if (loser)
    {
        game_ui->display_board(loser);
    }
    else
    {
        game_ui->display_board(nullptr);
    }

    cleanMem(game_ui, board, players);
}

/**
 * @brief Instantiates and runs the SUS game.
 */
void runSUS()
{
    UI<char> *SUS_ui = new SUS_UI();
    Board<char> *SUS_board = new SUS_Board();
    Player<char> **SUS_players = SUS_ui->setup_players();
    GameManager<char> SUS_game(SUS_board, SUS_players, SUS_ui);
    SUS_game.run();
    cleanMem(SUS_ui, SUS_board, SUS_players);
}

/**
 * @brief Instantiates and runs the Word XO game.
 */
void runWord()
{
    UI<char> *Word_ui = new Word_UI();
    Board<char> *Word_board = new Word_Board();
    Player<char> **Word_players = Word_ui->setup_players();
    GameManager<char> Word_game(Word_board, Word_players, Word_ui);
    Word_game.run();
    cleanMem(Word_ui, Word_board, Word_players);
}

/**
 * @brief Instantiates and runs the Memory XO game.
 */
void runMemoryXO()
{
    UI<char> *game_ui = new memory_XO_UI();
    Board<char> *memory_xo_board = new memory_XO_board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> memory_xo_game(memory_xo_board, players, game_ui);
    memory_xo_game.run();
    cleanMem(game_ui, memory_xo_board, players);
}

/**
 * @brief Instantiates and runs the Numerical XO game (uses int template).
 */
void runNumerical()
{
    UI<int> *game_ui = new Numerical_UI();
    Board<int> *Numerical_board = new Numerical_Board();
    Player<int> **players = game_ui->setup_players();
    GameManager<int> Numerical_game(Numerical_board, players, game_ui);
    Numerical_game.run();
    cleanMem(game_ui, Numerical_board, players);
}

/**
 * @brief Instantiates and runs the 4x4 XO game.
 */
void run4x4XO()
{
    UI<char> *game_ui = new _4x4_XO_UI();
    Board<char> *_4x4_XO_board = new _4x4_XO_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> _4x4_XO_game(_4x4_XO_board, players, game_ui);
    _4x4_XO_game.run();
    cleanMem(game_ui, _4x4_XO_board, players);
}

/**
 * @brief Instantiates and runs the Pyramid XO game.
 */
void runPyramidXO()
{
    UI<char> *game_ui = new Pyramid_XO_UI();
    Board<char> *Pyramid_board = new Pyramid_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> Pyramid_game(Pyramid_board, players, game_ui);
    Pyramid_game.run();
    cleanMem(game_ui, Pyramid_board, players);
}

/**
 * @brief Instantiates and runs the Four-in-a-Row (Connect 4) game.
 */
void runFouInARow()
{
    UI<char> *game_ui = new Four_in_a_row_UI();
    Board<char> *four_in_a_row_board = new Four_in_a_row_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> fourInARow_game(four_in_a_row_board, players, game_ui);
    fourInARow_game.run();
    cleanMem(game_ui, four_in_a_row_board, players);
}

/**
 * @brief Instantiates and runs the 5x5 Tic-Tac-Toe game.
 */
void run5X5()
{
    UI<char> *game_ui = new FiveXFive_UI();
    Board<char> *fiveXFive_board = new FiveXFive_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> FiveXFive_game(fiveXFive_board, players, game_ui);
    FiveXFive_game.run();
    cleanMem(game_ui, fiveXFive_board, players);
}

/**
 * @brief Instantiates and runs the Ultimate Tic-Tac-Toe game.
 */
void runUltimate()
{
    UI<char> *game_ui = new Ultimate_UI();
    Board<char> *Ultimate_board = new Ultimate_Board();
    Player<char> **players = game_ui->setup_players();
    GameManager<char> FiveXFive_game(Ultimate_board, players, game_ui);
    FiveXFive_game.run();
    cleanMem(game_ui, Ultimate_board, players);
}