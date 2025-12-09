#pragma once
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Numerical_UI
 * @brief User Interface handler for Numerical Tic-Tac-Toe.
 * @details Handles input for integers instead of characters.
 * Manages player setup (assigning Odd vs Even).
 * @see UI
 */
class Numerical_UI : public UI<int>
{
public:
    /**
     * @brief Constructor.
     * @details Sets the welcome message "Welcome to Numerical X-O".
     */
    Numerical_UI();

    /**
     * @brief Destructor.
     */
    ~Numerical_UI() {};

    /**
     * @brief Creates a player.
     * @param name Player name.
     * @param numtype Player "symbol" which actually represents type: 0 (Odd) or 1 (Even).
     * @param type Player type (Human/Computer).
     * @return Pointer to new Player object.
     */
    Player<int> *create_player(string &name, int numtype, PlayerType type);

    /**
     * @brief Sets up players for the game.
     * @details Overrides base setup to strictly assign Player 1 as Odd and Player 2 as Even.
     * @return Array of two Player pointers.
     */
    Player<int> **setup_players() override;

    /**
     * @brief Gets a move from the player.
     * @details
     * - Human: Asks for coordinates (0-2) AND a number to place.
     * Validates that the coordinates are empty and the number is available.
     * - Computer: Randomly picks an available number and a random empty spot.
     * @param player The current player.
     * @return Pointer to the Move object.
     */
    virtual Move<int> *get_move(Player<int> *player) override;
};