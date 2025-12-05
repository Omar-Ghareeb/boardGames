#pragma once
#include "../../BoardGame_Classes.h"
#include <queue>
using namespace std;

/**
 * @class Word_Board
 * @brief A 3x3 Board variant where players place letters to form words.
 * @details In this game, players do not have fixed symbols (like X or O).
 * Instead, they choose a letter and a position on each turn.
 * The goal is to form a valid 3-letter word (based on a dictionary file)
 * horizontally, vertically, or diagonally.
 * @see Board
 */
class Word_Board : public Board<char>
{
private:
    char blank_symbol = '.'; ///< Symbol representing an empty cell.

public:
    /**
     * @brief Constructor. Initializes a 3x3 board.
     */
    Word_Board();

    /**
     * @brief Updates the board with a move.
     * @details Validates that the input character is an alphabet letter (A-Z or a-z)
     * and that the target cell is empty. Converts input to uppercase.
     * @param move The move containing coordinates (x, y) and the chosen character.
     * @return true if the move is valid, false otherwise.
     */
    bool update_board(Move<char> *move);

    /**
     * @brief Checks if the latest move formed a valid word.
     * @details Opens an external file "dic.txt" and checks every word in it against
     * the rows, columns, and diagonals of the board. Checks both forward and reverse.
     * @param player The player who made the move.
     * @return true if a valid 3-letter word exists on the board.
     */
    bool is_win(Player<char> *player);

    /**
     * @brief Checks if the player loses.
     * @return Always false in this implementation.
     */
    bool is_lose(Player<char> *) { return false; };

    /**
     * @brief Checks if the game is a draw.
     * @details A draw occurs if the board is full (9 moves) and no word has been formed.
     * @param player The current player.
     * @return true if the game is a draw.
     */
    bool is_draw(Player<char> *player);

    /**
     * @brief Checks if the game is over.
     * @param player The current player.
     * @return true if there is a win or a draw.
     */
    bool game_is_over(Player<char> *player);
};