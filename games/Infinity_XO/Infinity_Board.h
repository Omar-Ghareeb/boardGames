#pragma once
#include "../../BoardGame_Classes.h"
#include <queue>
using namespace std;

/**
 * @class infinity_Board
 * @brief A 3x3 Tic-Tac-Toe variant where moves expire.
 * @details This board functions like a standard 3x3 board but adds a queue to track moves.
 * Based on the implementation, every 3rd move (global count), the oldest move on the board
 * is removed. This prevents the board from filling up quickly and adds a dynamic strategy.
 * @see Board
 */
class infinity_Board : public Board<char>
{
private:
    char blank_symbol = '.'; ///< Symbol representing an empty cell.

public:
    /**
     * @brief Constructor. Initializes a 3x3 board.
     */
    infinity_Board();

    /**
     * @brief Queue to store the history of moves coordinates (x, y).
     * Used to identify which move is the "oldest" when removal is triggered.
     */
    queue<pair<int, int>> moves;

    /**
     * @brief Counter for the total number of moves made in the game so far.
     */
    int NoOfMoves = 0;

    /**
     * @brief Updates the board with a player's move and handles move expiration.
     * @details
     * 1. Places the new symbol on the board.
     * 2. Pushes the move coordinates to the `moves` queue.
     * 3. Increments `NoOfMoves`.
     * 4. If `NoOfMoves` is a multiple of 3, the oldest move (front of the queue) is removed (set to blank).
     * @param move Pointer to a Move<char> object containing move coordinates and symbol.
     * @return true if the move is valid and successfully applied, false otherwise.
     */
    bool update_board(Move<char> *move);

    /**
     * @brief Checks if the given player has won the game.
     * @details Standard 3x3 win check (rows, columns, diagonals).
     * @param player Pointer to the player being checked.
     * @return true if the player has a winning line, false otherwise.
     */
    bool is_win(Player<char> *player);

    /**
     * @brief Checks if the given player has lost the game.
     * @param player Pointer to the player being checked.
     * @return Always returns false (not used in this logic).
     */
    bool is_lose(Player<char> *) { return false; };

    /**
     * @brief Checks if the game has ended in a draw.
     * @details A draw occurs if 9 moves are actively on the board without a winner.
     * Note: Due to the move removal logic, reaching 9 active moves is harder than standard XO.
     * @param player Pointer to the player being checked.
     * @return true if board is full and no winner.
     */
    bool is_draw(Player<char> *player);

    /**
     * @brief Determines if the game is over (win or draw).
     * @param player Pointer to the player to evaluate.
     * @return true if the game has ended, false otherwise.
     */
    bool game_is_over(Player<char> *player);
};