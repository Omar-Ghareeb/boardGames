#pragma once
#include "../../BoardGame_Classes.h"
#include <vector>
/**
 * @class Obstacles_Board
 * @brief A 6x6 Board implementing the Obstacles Tic-Tac-Toe logic.
 * @details it is a regular tic tac toe but the player loses when forming a line (horizontally, vertically, or diagonally).
 * @see Board
 */
class Obstacles_Board : public Board<char>
{
private:
    char blank_symbol = '.';  // Symbol representing an empty cell.
    int nombreMoves = 0; // counter to track the number of moves.

public:
    /**
   * @brief Constructor. Initializes a 6x6 board.
   */
    Obstacles_Board();
    /**
     * @brief Updates the board with 2 obstacles at random places.
     * @param int n the number of the obstacles to add.
     */
    void addRandomObstacles(int n);
    /**
     * @brief Updates the board with a move.
     * @param move Pointer to the move (x, y, symbol).
     */
    bool update_board(Move<char> *move) override;
    /**
     * @brief Checks if the player formed a line (horizontally, vertically, or diagonally).
     * @param player Pointer to the player.
     * @return true if wins.
     */
    bool is_win(Player<char> *player) override;
    /**
     * @brief Checks if the player loses. Always false here.
     */
    bool is_lose(Player<char> *) override { return false; };
    /**
   * @brief Checks if the game is a draw.
   * @details A draw occurs if  (n_moves >= 36).
   * @param player Pointer to the player.
   * @return true if draw.
   */
    bool is_draw(Player<char> *player) override;
    /**
    * @brief Checks if the game is over.
    * @param player Pointer to the player.
    * @return true if win or draw.
    */
    bool game_is_over(Player<char> *player) override;
};
