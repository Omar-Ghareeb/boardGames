#pragma once
#include "BoardGame_Classes.h"


/**
 * @class Four_in_a_row_UI
 * @brief User Interface handler for the four_in_a_row game.
 * @details Handles player creation and move input for the 3x3 four_in_a_row board.
 * @see UI
 */
class Four_in_a_row_UI : public UI<char>
{
private:
    int available[7] = {5, 5, 5, 5, 5, 5, 5};///<checks the available move in each column.

public:

    /**
    * @brief Constructs Four_in_a_row_UI object.
    * @details Initializes the base `UI<char>` class with the welcome message "Welcome to Four in a row game".
    */
    Four_in_a_row_UI();

    /**
    * @brief Creates a player of the specified type.
    * @param name Name of the player.
    * @param symbol Character symbol ('X' or 'O') assigned to the player.
    * @param type The type of the player (Human or Computer).
    * @return Pointer to the newly created Player<char> instance.
    */
    Player<char> *create_player(string &name, char symbol, PlayerType type);

    /**
    * @brief Retrieves the next move from a player.
    * @details
    * - Human: Prompts for y coordinates.
    * - Computer: Generates random column and get the available x from it to get a valid move.
    * @param player Pointer to the player whose move is being requested.
    * @return A pointer to a new `Move<char>` object representing the player's action.
    */
    virtual Move<char> *get_move(Player<char> *player);
};
