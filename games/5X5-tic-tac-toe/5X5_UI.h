#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;

/**
 * @class FiveXFive_UI
 * @brief User Interface handler for the 5x5 Tic-Tac-Toe game.
 * @details Handles player creation, move input (Human vs Computer), and display messages.
 * * @see UI
 */
class FiveXFive_UI : public UI<char>
{
public:
    /**
     * @brief Constructs a FiveXFive_UI object.
     * @details Initializes the base `UI<char>` class with the welcome message "Welcome to FiveXFive XO"
     * and sets the cell width for display.
     */
    FiveXFive_UI();

    /**
     * @brief Destructor for FiveXFive_UI.
     */
    ~FiveXFive_UI() {};

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
     * @details If the player is HUMAN, prompts for coordinates (0-4).
     * If the player is COMPUTER, generates a random valid move.
     * @param player Pointer to the player whose move is being requested.
     * @return A pointer to a new `Move<char>` object representing the player's action.
     */
    virtual Move<char> *get_move(Player<char> *player);
};