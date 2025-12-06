#pragma once
#include "../../BoardGame_Classes.h"

using namespace std;

/**
 * @class SUS_Board
 * @brief Represents the SUS game board.
 *
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the SUS (S,U) game, including
 * move updates, win/draw detection, and adds a function to check number of SUS on board.
 *
 * @see Board
 */
class SUS_Board : public Board<char>
{
private:
    char blank_symbol = '.'; ///< Character used to represent an empty cell on the board.

public:
    /**
    * @brief Default constructor that initializes a 3x3 board.
    */
    SUS_Board();

    int SUSPlayer1 = 0;///< Counter for the total number of SUS made by player1.
    int SUSPlayer2 = 0;///< Counter for the total number of SUS made by player2.

    /**
    * @brief Updates SUS count for this player.
    * @details
    * 1. Get the number of all SUS on board.
    * 2. Check if this is player1(sym='S') or player2 (sym='U')
    * 3. Update current player SUS count by subtracting player2 SUS count from all SUS count on board
    * @param Player's symbol to check which player to update their SUS value .
    * @return nothing.
    */
    void checkNumOfSUS(char sym);

    /**
    * @brief Updates the board with a player's move.
    * @details
    * 1. Places the new symbol on the board.
    * 2. update SUS for player1 and SUS for player2 with every move.
    * @param move Pointer to a Move<char> object containing move coordinates and symbol.
    * @return true if the move is valid and successfully applied, false otherwise.
    */
    bool update_board(Move<char> *move);

    /**
    * @brief Checks when the board is full if the given player(player1 'S') has won the game.
    * @param player Pointer to the player being checked(Always player1'S').
    * @return true is player1 has more SUS than Player2.
    */
    bool is_win(Player<char> *player);

    /**
    * @brief Checks if the game has ended in a draw.
    * @param player Pointer to the player being checked.
    * @return true if all cells are filled and number of SUS for player1=player2, false otherwise.
    */
    bool is_draw(Player<char> *player);

    /**
    * @brief Checks when the board is full if the given player(player1 'S') has lost the game.
    * @param player Pointer to the player being checked(Always player1'S').
    * @return true is player1 has less SUS than Player2.
    */
    bool is_lose(Player<char> *player);

    /**
    * @brief Determines if the game is over (win or draw).
    * @param player Pointer to the player to evaluate.
    * @return true if the game has ended, false otherwise.
    */
    bool game_is_over(Player<char> *player);
};
