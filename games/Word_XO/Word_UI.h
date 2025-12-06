#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;

/**
 * @class Word_UI
 * @brief User Interface handler for the Word XO game.
 * @details Handles the specific input requirements for this game (coordinates + character selection).
 * @see UI
 */
class Word_UI : public UI<char>
{
public:
    /**
     * @brief Constructs the Word_UI.
     * @details Sets the welcome message and cell width.
     */
    Word_UI();

    /**
     * @brief Destructor.
     */
    ~Word_UI() {};

    /**
     * @brief Creates a player.
     * @param name Player name.
     * @param symbol Player ID symbol (internally used as '1' or '2', not the board char).
     * @param type Human or Computer.
     * @return Pointer to new Player object.
     */
    Player<char> *create_player(string &name, char symbol, PlayerType type);

    /**
     * @brief Sets up the two players for the game.
     * @details Overrides the base setup to assign internal IDs '1' and '2'
     * instead of fixed 'X' or 'O', since players choose different letters every turn.
     * @return Array of two Player pointers.
     */
    Player<char> **setup_players() override;

    /**
     * @brief Gets a move from the player.
     * @details
     * - Human: Asks for X, Y coordinates AND a character to place.
     * - Computer: Generates random X, Y and a random character (a-z).
     * @param player The player whose turn it is.
     * @return Pointer to the Move object.
     */
    virtual Move<char> *get_move(Player<char> *player);
};