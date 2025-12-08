#pragma once
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class _4x4_XO_Board
 * @brief A 4x4 Tic-Tac-Toe variant.
 * @details The board size is 4x4, but the winning condition requires only
 * 3 consecutive symbols (horizontally, vertically, or diagonally),
 * rather than filling the entire row/column.
 * @see Board
 */
class _4x4_XO_Board : public Board<char>
{
private:
    char blank_symbol = '.'; ///< Symbol representing an empty cell.

public:
    /**
     * @brief Constructor. Initializes a 4x4 board.
     */
    _4x4_XO_Board();

    /**
     * @brief Updates the board with a move.
     * @param move The move containing coordinates and symbol.
     * @return true if the move is valid (within bounds and cell empty), false otherwise.
     */
    bool update_board(Move<char> *move) override;

    /**
     * @brief Checks if a player has won.
     * @details Scans for any sequence of 3 identical symbols in a row, column, or diagonal.
     * @param player The player to check.
     * @return true if a winning sequence is found.
     */
    bool is_win(Player<char> *player) override;

    /**
     * @brief Checks if the player loses.
     * @return Always false for this game variant.
     */
    bool is_lose(Player<char> *player) override { return false; }

    /**
     * @brief Checks for a draw.
     * @details A draw occurs if the board is full (16 moves) and no winner exists.
     * @param player The current player.
     * @return true if the game is a draw.
     */
    bool is_draw(Player<char> *player) override;

    /**
     * @brief Checks if the game is over.
     * @param player The current player.
     * @return true if win or draw.
     */
    bool game_is_over(Player<char> *player) override;
};
// GAMES_4X4_XO_4X4_XO_BOARD_H