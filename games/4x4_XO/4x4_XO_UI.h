#pragma once
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class _4x4_XO_UI
 * @brief User Interface handler for the 4x4 XO game.
 * @see UI
 */
class _4x4_XO_UI : public UI<char>
{
public:
    /**
     * @brief Constructor.
     * @details Sets the welcome message and cell width (4).
     */
    _4x4_XO_UI();

    /**
     * @brief Destructor.
     */
    ~_4x4_XO_UI() {};

    /**
     * @brief Creates a player.
     * @param name Player name.
     * @param symbol Player symbol (X or O).
     * @param type Player type (Human or Computer).
     * @return Pointer to the new Player object.
     */
    Player<char> *create_player(string &name, char symbol, PlayerType type);

    /**
     * @brief Gets a move from the player.
     * @details
     * - Human: Asks for coordinates 0-3.
     * - Computer: Random valid coordinates.
     * @param player The current player.
     * @return Pointer to the Move object.
     */
    virtual Move<char> *get_move(Player<char> *player) override;
};