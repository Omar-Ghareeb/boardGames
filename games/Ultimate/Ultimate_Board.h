#pragma once
#include "../../BoardGame_Classes.h"
#include <cstring>

using namespace std;

/**
 * @class Ultimate_Board
 * @brief A 9x9 Board implementing the Ultimate Tic-Tac-Toe logic.
 * @details The game consists of a 9x9 grid, conceptually divided into nine 3x3 sub-grids.
 * When a player wins a 3x3 sub-grid, that entire sub-grid is considered "captured" by that player.
 * The goal is to win three captured sub-grids in a row (horizontally, vertically, or diagonally)
 * on the meta-board.
 * @see Board
 */
class Ultimate_Board : public Board<char>
{
private:
    char blank_symbol = '.'; ///< Symbol representing an empty cell.

    /** * @brief Counter for remaining moves/cells.
     * Initialized to 81 (9x9). Used to determine draws or game end.
     */
    int n_moves = 81;

    /**
     * @brief The meta-board tracking the state of the nine 3x3 sub-grids.
     * 'c' indicates the sub-grid is still contested (in play).
     * 'X' or 'O' indicates the sub-grid has been won by that player.
     */
    char boards[3][3];

public:
    /**
     * @brief Constructor. Initializes a 9x9 board and resets the meta-board.
     */
    Ultimate_Board();

    /**
     * @brief Checks if a move completed a line in a sub-grid.
     * @details If a sub-grid is won, this function:
     * 1. Updates the `boards` meta-grid with the winner's symbol.
     * 2. Overwrites all cells in that 3x3 sub-grid on the main board with the winner's symbol
     * to visually indicate it is captured.
     * 3. Adjusts `n_moves` to reflect that these cells are no longer playable.
     * @param sym The symbol of the player who made the last move.
     */
    void MiniGridDOne(char sym);

    /**
     * @brief Updates the board with a move.
     * @param move Pointer to the move (x, y, symbol).
     * @return true if the move is valid, false otherwise.
     */
    bool update_board(Move<char> *move);

    /**
     * @brief Checks if a player has won the overall game.
     * @details Checks the 3x3 `boards` meta-grid for a winning line.
     * @param player Pointer to the player.
     * @return true if the player has won 3 sub-grids in a row.
     */
    bool is_win(Player<char> *player);

    /**
     * @brief Checks if the player loses. Always false here.
     */
    bool is_lose(Player<char> *) { return false; };

    /**
     * @brief Checks if the game is a draw.
     * @details A draw occurs if no moves are left (n_moves == 0) and no one has won.
     * @param player Pointer to the player.
     * @return true if draw.
     */
    bool is_draw(Player<char> *player);

    /**
     * @brief Checks if the game is over.
     * @param player Pointer to the player.
     * @return true if win or draw.
     */
    bool game_is_over(Player<char> *player);
};