#pragma once
#ifndef DIAMOND_BOARD_H
#define DIAMOND_BOARD_H
#include "../../BoardGame_Classes.h"
#include <vector>

/**
 * @class Diamond_Board
 * @brief A 7x7 board implementing the Diamond Tic-Tac-Toe logic.
 * @details The game consists of a 5x5 grid, conceptually shaped as a diamond.
 * A player wins by simultaneously completing:
 *  - A line of 4 marks (horizontally, vertically, or diagonally)
 *  - A line of 3 marks (horizontally, vertically, or diagonally)
 * These two lines must intersect in exactly one cell and be in different directions.
 * @see Board
 */
class Diamond_Board : public Board<char>
{
private:
    char blank_symbol = '.'; // Symbol representing an empty cell.
    char invalid_symbol = ' '; //  Symbol representing an invalid cell.
    int Moves = 0;
    vector<pair<int, int>> invalid // vector for invalid cells.
    {
            {0,0},{0,1},{0,2},      {0,4},{0,5},{0,6},
            {1,0},{1,1},                  {1,5},{1,6},
            {2,0},                              {2,6},
            
            {4,0},                              {4,6},
            {5,0},{5,1},                        {5,6},
            {6,0},{6,1},{6,2},      {6,4},{6,5},{6,6},
    };
    
public:
    /**
    * @brief Constructor. Initializes a 7x7 board.
    */
    Diamond_Board();
    /**
     * @brief Updates the board with a move.
     * @param move Pointer to the move (x, y, symbol).
     * @return true if the move is valid, false otherwise.
     */
    bool update_board(Move<char>* move) override;
    /**
     * @brief Checks if a player has won the overall game.
     * @param player Pointer to the player.
     * @return true if not same direction and share one cell.
     */
    bool is_win(Player<char>* player) override;
    /**
     * @brief Checks if the player loses. Always false here.
     */
    bool is_lose(Player<char>* player) override;
    /**
     * @brief Checks if the game is a draw.
     * @details A draw occurs if  (n_moves == 25) and no one has won.
     * @param player Pointer to the player.
     * @return true if draw.
     */
    bool is_draw(Player<char>* player) override;
    /**
     * @brief Checks if the game is over.
     * @param player Pointer to the player.
     * @return true if win or draw.
     */
    bool game_is_over(Player<char>* player) override;
    /**
     * @brief Checks the cell is valid.
     * @param int x and y for the rows and cols.
     * @return false if (x,y) belong to the invalid vector and true otherwise.
     */
    bool is_valid_cell(int x, int y);
    /**
     * @brief Checks the direction of the lines (horizontally, vertically, or diagonally).
     * @param player Pointer to the player, a grid vector for the lines having 3 marks,
          a grid vector for the lines having 4 marks.
     */
    void check_direction(Player<char>* player, vector<vector<pair<int, int>>>& lines_3,
        vector<vector<pair<int, int>>>& lines_4) ;
    /**
     * @brief Checks if the two lines intersecte at exactry one cell by tracking count.
     * @param constants vectors that have the 3 marks line and the 4 marks line of the player.
     * @return false if the count is bigger than one, true if count==1.
     */
    bool share_one_cell(const vector<pair<int, int>>& ligne3,
        const vector<pair<int, int>>& ligne4);
    /**
     * @brief Checks if the two lines are parallel or same direction.
     * @param constants vectors that have the 3 marks line and the 4 marks line of the player.
     * @return true if they are at the same direction.
     */
    bool same_direction(const vector<pair<int, int>>& a,
        const vector<pair<int, int>>& b);
};

#endif 