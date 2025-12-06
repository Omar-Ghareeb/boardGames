#pragma once
#include "../../BoardGame_Classes.h"

/**
 * @class Four_in_a_row_Board
 * @brief Represents the Four_in_a_row game board.
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the Four_in_a_row game, including
 * move updates, win/draw detection, and display functions.
 * @see Board
 */
class Four_in_a_row_Board : public Board<char>
{
private:
    char blank_symbol = '.';///< Character used to represent an empty cell on the board.
    int available[7] = {5, 5, 5, 5, 5, 5, 5};///<checks the available move in each column.

public:

    /**
    * @brief Default constructor that initializes a 6x7 board.
    */
    Four_in_a_row_Board();

    /**
    * @brief Updates the board with a player's move.
    * @details get the move's y coordinate and set x to be the available value in this y column.
    * @param move Pointer to a Move<char> object containing move coordinates and symbol.
    * @return true if the move is valid and successfully applied, false otherwise.
    */
    bool update_board(Move<char> *move);
    /**
    * @brief Checks if the given player has won the game.
    * @param player Pointer to the player being checked.
    * @return true if the player has a winning line, false otherwise.
    */
    bool is_win(Player<char> *player);

    /**
    * @brief Checks if the game has ended in a draw.
    * @param player Pointer to the player being checked.
    * @return true if all cells are filled and no player has won, false otherwise.
    */
    bool is_draw(Player<char> *player);

    /**
    * @brief Checks if the given player has lost the game.
    * @param player Pointer to the player being checked.
    * @return Always returns false (not used in four_in_a_row logic).
    */
    bool is_lose(Player<char> *) { return false; }

    /**
    * @brief Determines if the game is over (win or draw).
    * @param player Pointer to the player to evaluate.
    * @return true if the game has ended, false otherwise.
    */
    bool game_is_over(Player<char> *player);
};
