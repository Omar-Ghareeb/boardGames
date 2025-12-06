#pragma once
#ifndef MISERE_UI_H
#define MISERE_UI_H

#include "../../BoardGame_Classes.h"
#include "Misere_Board.h"
#include <iostream>
/**
 * @class Misere_UI
 * @brief User Interface for Misere Tic-Tac-Toe.
 * @see UI
 */
class Misere_UI : public UI<char> 
{
public: 
    /**
     * @brief Constructor.
     */
    Misere_UI() :UI<char>("Welcome to Misere Tic Tac Toe", 9) {}

    Misere_UI(Board<char>* b) :UI<char>("Welcome to Misere Tic Tac Toe", 9)
    {
        board = b;
    }
    /**
    * @brief Destructor.
    */
    ~Misere_UI() {}
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
    /**
     * @brief Sets up the players for the game.
     *
     * This function initializes and returns an array of pointers to Player objects.
     * It is intended to be overridden in derived classes for specific game setups.
     *
     * @return Player<char>** Pointer to an array of two Player<char> pointers.
     */ 
    Player<char>** setup_players() override;
    /**
     * @brief Displays the game board highlighting the loser.
     *
     * This function prints the current state of the board to the console.
     * It can be used to visually indicate which player lost the game.
     *
     * @param loser Pointer to the Player<char> who lost the game.
      */
    void display_board(Player<char>* loser);

private:
    /**
     * @brief The main game board.
     *
     * This is a  pointer to array representing the game grid.
     * Each cell stores a symbol of type `char` (e.g., 'X', 'O', or blank).
     * 
     * Prints X/O DIED at the second row.
    */
    Board<char>* board;
};

#endif


