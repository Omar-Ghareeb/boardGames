#include "Diamond_UI.h"
#include <iostream>
#include <iomanip>
using namespace std;

Player<char>* Diamond_UI::create_player(string& name, char symbol, PlayerType type) {
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* Diamond_UI::get_move(Player<char>* player) {
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) 
    {
        cout << "\nPlease enter your move x and y (0 to 4): \n";
        cin >> x >> y;
      
    }
    else if (player->get_type() == PlayerType::COMPUTER) 
    {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();

    }
    return new Move<char>(x, y, player->get_symbol());
}
