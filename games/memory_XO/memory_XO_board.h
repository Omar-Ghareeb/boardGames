#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;

/**
 * @class memory_XO_board
* @brief Represents the Tic-Tac-Toe game board.
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the memory_XO game, including
 * move updates, win/draw detection, and display functions.
 * @see Board
 */
class memory_XO_board : public Board<char>
{
private:
    char blank_symbol = '.';///< Character used to represent an empty cell on the board.

public:

    /**
    * @brief Default constructor that initializes a 3x3 X-O board.
    */
    memory_XO_board();

    /**
    * @brief Updates the board with a player's move.
    * @param move Pointer to a Move<char> object containing move coordinates and symbol.
    * @return true if the move is valid and successfully applied, false otherwise.
    */
    bool update_board(Move<char> *move);
    /**
    * @brief Checks if the given player has won the game.
    * @details displays the board if the player win
    * @param player Pointer to the player being checked.
    * @return true if the player has a winning line, false otherwise.
    */
    bool is_win(Player<char> *player);

    /**
    * @brief Checks if the given player has lost the game.
    * @param player Pointer to the player being checked.
    * @return Always returns false (not used in X-O logic).
    */
    bool is_lose(Player<char> *) { return false; };

    /**
    * @brief Checks if the game has ended in a draw.
    * @details displays the board if it's draw
    * @param player Pointer to the player being checked.
    * @return true if all cells are filled and no player has won, false otherwise.
    */
    bool is_draw(Player<char> *player);

    /**
    * @brief Determines if the game is over (win or draw).
    * @param player Pointer to the player to evaluate.
    * @return true if the game has ended, false otherwise.
    */
    bool game_is_over(Player<char> *player);
    /**
    * @brief displays the board.
    */
    void display_real_board();
};
