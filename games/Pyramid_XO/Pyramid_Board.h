#pragma once
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Pyramid_Board
 * @brief A Pyramid-shaped Tic-Tac-Toe board.
 * @details The board is logically a 3x5 matrix, but only specific cells form the pyramid:
 * - Row 0: Cell 2 (Top tip)
 * - Row 1: Cells 1, 2, 3 (Middle)
 * - Row 2: Cells 0, 1, 2, 3, 4 (Base)
 * Winning lines can be horizontal, vertical (center column), or diagonal.
 * @see Board
 */
class Pyramid_Board : public Board<char>
{
private:
    char blank_symbol = '.';   ///< Symbol for a valid empty spot.
    char invalid_symbol = ' '; ///< Symbol for non-playable areas of the 3x5 grid.

    /**
     * @brief Stores all possible 3-cell coordinates that constitute a win.
     */
    vector<vector<pair<int, int>>> winning_lines;

    /**
     * @brief Populates the `winning_lines` vector with valid winning combinations.
     */
    void init_winning_lines();

public:
    /**
     * @brief Constructor.
     * @details Initializes a 3x5 grid, marks non-pyramid cells as invalid,
     * and sets valid pyramid cells to the blank symbol.
     */
    Pyramid_Board();

    /**
     * @brief Updates the board with a move.
     * @param move The move containing coordinates and symbol.
     * @return true if the move is within the pyramid bounds and the cell is empty.
     */
    bool update_board(Move<char> *move) override;

    /**
     * @brief Checks if a player has won.
     * @details Iterates through the pre-defined `winning_lines` to see if the player
     * occupies all 3 cells of any line.
     * @param player The player to check.
     * @return true if a winning line is found.
     */
    bool is_win(Player<char> *player) override;

    /**
     * @brief Checks if the player loses.
     * @return Always false.
     */
    bool is_lose(Player<char> *player) override { return false; };

    /**
     * @brief Checks for a draw.
     * @details A draw occurs if 9 moves have been made (filling the pyramid) with no winner.
     * @param player The current player.
     * @return true if draw.
     */
    bool is_draw(Player<char> *player) override;

    /**
     * @brief Checks if the game is over.
     * @return true if win or draw.
     */
    bool game_is_over(Player<char> *player) override;

    /**
     * @brief Validates if a coordinate is part of the playable pyramid.
     * @param r Row index.
     * @param c Column index.
     * @return true if (r, c) is a valid pyramid cell.
     */
    bool is_valid_cell(int r, int c) const;

    /**
     * @brief Getter for the blank symbol.
     */
    char get_blank_symbol() const { return blank_symbol; }

    /**
     * @brief Helper to get cell content safely.
     */
    char get_cell(int r, int c) const { return board[r][c]; }
};