#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;
class Infinity_UI : public UI<char>
{
public:
    /**
     * @brief Constructs an Infinity_UI object.
     *
     * Initializes the base `UI<char>` class with the welcome message "FCAI X-O".
     */
    Infinity_UI();

    /**
     * @brief Destructor for Infinity_UI.
     */
    ~Infinity_UI() {};

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
     * @param player Pointer to the player whose move is being requested.
     * @return A pointer to a new `Move<char>` object representing the player's action.
     */
    virtual Move<char> *get_move(Player<char> *player);
};
