#pragma once

#include "../../BoardGame_Classes.h"
#include "Obstacles_Board.h"
#include <iostream>
/**
 * @class Obstacles_UI
 * @brief User Interface for Obstacles Tic-Tac-Toe.
 * @see UI
 */
class Obstacles_UI : public UI<char>
{
public:
    /**
     * @brief Constructor.
     */
    Obstacles_UI();
    /**
    * @brief Destructor.
    */
    ~Obstacles_UI() {}
    /**
     * @brief Gets the move coordinates from the player.
     * @details
     * - Human: Asks for inputs.
     * - Computer: Generates random valid coordinates.
     * @param player The current player.
     * @return Pointer to the Move object.
     */
    virtual Move<char> *get_move(Player<char> *player);
    /**
    * @brief Creates a Human or Computer player.
    * @param name Player's name.
    * @param symbol Player's symbol.
    * @param type PlayerType (HUMAN/COMPUTER).
    * @return Pointer to the new Player object.
    */
    Player<char> *create_player(string &name, char symbol, PlayerType type);
};
