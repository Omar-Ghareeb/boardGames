#include "Ultimate_UI.h"
using namespace std;

// Note: String "Welcome to Infinity XO" might be a copy-paste remnant;
// normally this would be "Welcome to Ultimate XO".
Ultimate_UI::Ultimate_UI() : UI<char>("Welcome to Infinity XO", 3) {}

Player<char> *Ultimate_UI::create_player(string &name, char symbol, PlayerType type)
{
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
         << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char> *Ultimate_UI::get_move(Player<char> *player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        // Note: The prompt says 0 to 2, but Ultimate XO usually requires 0-8 coordinates
        // or a specific coordinate selection system for the 9x9 grid.
        // Based on the Board class, inputs should likely be 0-8.
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER)
    {
        // Random move generation for 9x9 board
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
    }
    return new Move<char>(x, y, player->get_symbol());
}