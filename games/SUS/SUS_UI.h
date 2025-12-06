#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;

/**
 * @class SUS_UI
 * @brief User Interface handler for the SUS game.
 * @details Handles player creation and move input for the 3x3 SUS board.
 * @see UI
 */
class SUS_UI : public UI<char>
{
public:

    /**
    * @brief Constructs an SUS_UI object.
    * @details Initializes the base `UI<char>` class with the welcome message "Welcome to SUS game".
    */
    SUS_UI();

    /**
    * @brief Destructor for SUS_UI.
    */
    ~SUS_UI() {};

    /**
    * @brief Creates a player of the specified type.
    * @param name Name of the player.
    * @param symbol Character symbol ('S' or 'U') assigned to the player.
    * @param type The type of the player (Human or Computer).
    * @return Pointer to the newly created Player<char> instance.
    */
    Player<char> *create_player(string &name, char symbol, PlayerType type);
    /**
    * @brief Set up players for the game.
    * @details makes player1's symbol 'S' and player2's symbol 'U'.
    */
    Player<char> **setup_players() override;

    /**
    * @brief Retrieves the next move from a player.
    * @details
    * - Human: Prompts for x and y coordinates (0-2).
    * - Computer: Generates random valid coordinates.
    * @param player Pointer to the player whose move is being requested.
    * @return A pointer to a new `Move<char>` object representing the player's action.
    */
    virtual Move<char> *get_move(Player<char> *player);
};
