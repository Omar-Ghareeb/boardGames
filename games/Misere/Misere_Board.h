#ifndef MISERE_BOARD_H
#define MISERE_BOARD_H
#include "../../BoardGame_Classes.h"
/**
 * @class Misere_Board
 * @brief A 3x3 Board implementing the Misere Tic-Tac-Toe logic.
 * @details it is a regular tic tac toe but the player loses when forming a line (horizontally, vertically, or diagonally).
 * @see Board
 */
class Misere_Board : public Board<char>
{
private:
    char blank_symbol = '.'; // Symbol representing an empty cell.
    int Moves = 0; // counter to track the number of moves.
    
public:
    /**
   * @brief Constructor. Initializes a 3x3 board.
   */
    Misere_Board();
    /**
     * @brief Updates the board with a move.
     * @param move Pointer to the move (x, y, symbol).
     */
    bool update_board(Move<char>* move) override;
    /**
     * @brief Checks if the player wins. Always false here.
     */
    bool is_win(Player<char>* player) override;
    /**
     * @brief Checks if the player formed a line (horizontally, vertically, or diagonally).
     * @param player Pointer to the player.
     * @return true if loses, false otherwise.
     */
    bool is_lose(Player<char>* player) override;
    /**
    * @brief Checks if the game is a draw.
    * @details A draw occurs if  (n_moves == 9) and no one has lost.
    * @param player Pointer to the player.
    * @return true if draw.
    */
    bool is_draw(Player<char>* player) override;
    /**
     * @brief Checks if the game is over.
     * @param player Pointer to the player.
     * @return true if lose or draw.
     */
    bool game_is_over(Player<char>* player) override;
    /**
     * @brief get the cell row and column number.
     * @param int r and c for the rows and cols..
     * @return the cell position.
     */
    char get_cell(int r, int c) const { return board[r][c]; }

  
};

#endif 