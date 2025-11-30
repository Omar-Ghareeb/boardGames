#include "5X5_UI.h"
using namespace std;

FiveXFive_UI::FiveXFive_UI() : UI<char>("Welcome to FiveXFive XO", 5) {}

Player<char> *FiveXFive_UI::create_player(string &name, char symbol, PlayerType type)
{
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
         << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char> *FiveXFive_UI::get_move(Player<char> *player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move x and y (0 to 4): ";
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER)
    {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
    }
    return new Move<char>(x, y, player->get_symbol());
}
