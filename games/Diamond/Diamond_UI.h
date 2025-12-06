#pragma once
#pragma once
#ifndef DIAMOND_UI_H
#define DIAMOND_UI_H

#include "../../BoardGame_Classes.h"
#include "Diamond_Board.h"
#include <iostream>

/**
 * @class Diamond_UI
 * @brief User Interface for Diamond Tic-Tac-Toe.
 * @see UI
 */
class Diamond_UI : public UI<char>
{
public:
    /**
     * @brief Constructor.
     */
    Diamond_UI() :UI<char>("Welcome to Diamond Tic Tac Toe", 11) {}
    /**
     * @brief Destructor.
     */
    ~Diamond_UI() {}
    /**
     * @brief Gets the move coordinates from the player.
     * @details
     * - Human: Asks for inputs.
     * - Computer: Generates random valid coordinates.
     * @param player The current player.
     * @return Pointer to the Move object.
     */
    virtual Move<char>* get_move(Player<char>* player);
    /**
     * @brief Creates a Human or Computer player.
     * @param name Player's name.
     * @param symbol Player's symbol.
     * @param type PlayerType (HUMAN/COMPUTER).
     * @return Pointer to the new Player object.
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type);

   
};

#endif