#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;

/**
 * @class Ultimate_UI
 * @brief User Interface for Ultimate Tic-Tac-Toe.
 * @see UI
 */
class Ultimate_UI : public UI<char>
{
public:
    /**
     * @brief Constructor.
     */
    Ultimate_UI();

    /**
     * @brief Destructor.
     */
    ~Ultimate_UI() {};

    /**
     * @brief Creates a Human or Computer player.
     * @param name Player's name.
     * @param symbol Player's symbol.
     * @param type PlayerType (HUMAN/COMPUTER).
     * @return Pointer to the new Player object.
     */
    Player<char> *create_player(string &name, char symbol, PlayerType type);

    /**
     * @brief Gets the move coordinates from the player.
     * @details
     * - Human: Asks for inputs.
     * - Computer: Generates random valid coordinates.
     * @param player The current player.
     * @return Pointer to the Move object.
     */
    virtual Move<char> *get_move(Player<char> *player);
};