#pragma once
#include "BoardGame_Classes.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @class Numerical_Board
 * @brief A 3x3 Tic-Tac-Toe variant using numbers.
 * @details
 * - Player 1 uses Odd numbers: {1, 3, 5, 7, 9}
 * - Player 2 uses Even numbers: {2, 4, 6, 8}
 * - The goal is to form a line (horizontal, vertical, or diagonal) that sums to exactly 15.
 * @see Board
 */
class Numerical_Board : public Board<int>
{
private:
    /** @brief Available odd numbers for Player 1. */
    vector<int> remaining_odd = {1, 3, 5, 7, 9};

    /** @brief Available even numbers for Player 2. */
    vector<int> remaining_even = {2, 4, 6, 8};

    /** @brief Symbol representing an empty cell (0). */
    int blank_symbol = 0;

public:
    /**
     * @brief Constructor. Initializes a 3x3 board with zeros.
     */
    Numerical_Board();

    /**
     * @brief Updates the board with a move.
     * @param move The move containing coordinates and the chosen number.
     * @return true if the move is valid.
     */
    bool update_board(Move<int> *move) override;

    /**
     * @brief Checks if a player has won.
     * @details Scans all rows, columns, and diagonals to see if any valid line sums to 15.
     * Note: Cells must be non-zero to count towards a win (avoids early false positives with zeros).
     * @param player The player to check.
     * @return true if a line sums to 15.
     */
    bool is_win(Player<int> *player) override;

    /**
     * @brief Checks if the player loses.
     * @return Always false for this game.
     */
    bool is_lose(Player<int> *player) override
    {
        return false;
    }

    /**
     * @brief Checks for a draw.
     * @details A draw occurs if 9 moves are made (board full) without a winner.
     * @param player The current player.
     * @return true if draw.
     */
    bool is_draw(Player<int> *player) override;

    /**
     * @brief Checks if the game is over.
     * @return true if win or draw.
     */
    bool game_is_over(Player<int> *player) override;

    /**
     * @brief Calculates the sum of values in three specific cells.
     * @param r0 Row of first cell.
     * @param c0 Col of first cell.
     * @param r1 Row of second cell.
     * @param c1 Col of second cell.
     * @param r2 Row of third cell.
     * @param c2 Col of third cell.
     * @return Sum of the three integers.
     */
    int line_sum(int r0, int c0, int r1, int c1, int r2, int c2);

    /**
     * @brief Checks if a specific number is still available for a player type.
     * @param number The number to check (e.g., 5).
     * @param numtype The player type (0 for Odd, 1 for Even).
     * @return true if the number is in the corresponding remaining vector.
     */
    bool is_number_available(int number, int numtype);

    /**
     * @brief Removes a number from the available pool after it's played.
     * @param number The number used.
     * @param numtype The player type (0 for Odd, 1 for Even).
     */
    void use_number(int number, int numtype);

    /** @brief Getter for remaining odd numbers. */
    vector<int> &get_remaining_odd() { return remaining_odd; }

    /** @brief Getter for remaining even numbers. */
    vector<int> &get_remaining_even() { return remaining_even; }

    /** @brief Helper to get the integer value at a specific cell. */
    int get_cell_symbol(int r, int c)
    {
        return board[r][c];
    }
};