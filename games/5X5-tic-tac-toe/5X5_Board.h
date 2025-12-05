#pragma once
#include "../../BoardGame_Classes.h"
#include <set>
#include <tuple>

/**
 * @class FiveXFive_Board
 * @brief A 5x5 Tic-Tac-Toe variant where the goal is to accumulate points.
 * @details In contrast to traditional Tic-Tac-Toe, the formation of a line does not end the game.
 * Rather, each distinct 3-in-a-row sequence (horizontal, vertical, or diagonal) earns points for the players.
 * Until the board is full (24 moves), the game goes on.
 * The player with the highest score wins.
 * * @see Board
 */
class FiveXFive_Board : public Board<char>
{
private:
    char blank_symbol = '.'; ///< Symbol representing an empty cell.
    int player1_Score = 0;   ///< Current score for Player 1 (X).
    int player2_Score = 0;   ///< Current score for Player 2 (O).

    /**
     * @brief Tracks winning sequences that have already been counted.
     * @details A set of tuples, where each tuple contains three pairs of (x, y) coordinates.
     * This ensures that a specific line of 3 symbols is not scored more than once.
     */
    set<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> done;

public:
    /**
     * @brief Constructor. Initializes a 5x5 board.
     */
    FiveXFive_Board();

    /**
     * @brief Updates the board with a move.
     * @param move The move to be applied.
     * @return true if the move is valid and applied, false otherwise.
     */
    bool update_board(Move<char> *move);

    /**
     * @brief Checks if a player has won immediately.
     * @details In this variant, there is no "instant win." The game relies on high scores
     * at the end. Therefore, this always returns false.
     * @param player The player to check.
     * @return Always false.
     */
    bool is_win(Player<char> *player) { return false; }

    /**
     * @brief Calculates and updates the score for the given player.
     * @details Scans rows, columns, and diagonals for sets of 3 identical symbols
     * that haven't been counted yet. Updates the internal score and the `done` set.
     * @param player The player who just moved.
     */
    void plus(Player<char> *player);

    /**
     * @brief Checks if the game is a draw.
     * @details A draw occurs if the board is full (24 moves) and scores are tied (implied by !is_lose).
     * @param player The current player.
     * @return true if the game ended in a draw.
     */
    bool is_draw(Player<char> *player);

    /**
     * @brief Checks if the current player has lost.
     * @details Logic: Calculates final scores. If the board is full (24 moves)
     * and Player 2's score < Player 1's score, Player 2 loses (or vice versa depending on perspective).
     * @param player The player to check.
     * @return true if the player has fewer points when the game ends.
     */
    bool is_lose(Player<char> *);

    /**
     * @brief Checks if the game is over.
     * @param player The current player.
     * @return true if the board is full (24 moves reached).
     */
    bool game_is_over(Player<char> *player);
};