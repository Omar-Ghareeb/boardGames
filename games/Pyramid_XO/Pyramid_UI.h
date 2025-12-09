#pragma once
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Pyramid_XO_UI
 * @brief User Interface handler for the Pyramid Tic-Tac-Toe game.
 * @details Handles input validation specific to the pyramid shape.
 * @see UI
 */
class Pyramid_XO_UI : public UI<char>
{
public:
    /**
     * @brief Constructor.
     * @details Sets the welcome message "Welcome to Pyramid X-O" and cell width.
     */
    Pyramid_XO_UI();

    /**
     * @brief Destructor.
     */
    ~Pyramid_XO_UI() {};

    /**
     * @brief Creates a player.
     * @param name Player name.
     * @param symbol Player symbol.
     * @param type Player type (Human/Computer).
     * @return Pointer to new Player object.
     */
    Player<char> *create_player(string &name, char symbol, PlayerType type);

    /**
     * @brief Gets a move from the player.
     * @details
     * - Human: Loops until the user enters coordinates that are both within bounds
     * (is_valid_cell) and unoccupied.
     * - Computer: Generates random valid coordinates based on the row index logic.
     * @param player The current player.
     * @return Pointer to the Move object.
     */
    virtual Move<char> *get_move(Player<char> *player) override;
};