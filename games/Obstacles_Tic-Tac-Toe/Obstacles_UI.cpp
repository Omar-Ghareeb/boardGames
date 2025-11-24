#include "Obstacles_UI.h"
#include <iostream>
#include <iomanip>
using namespace std;


Obstacles_UI::Obstacles_UI(): UI<char>("Welcome to Obstacles TicTac Toe", 2) {}

Player<char>* Obstacles_UI::create_player(string& name, char symbol, PlayerType type) {
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* Obstacles_UI::get_move(Player<char>* player) {
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 5): ";
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        x = rand() % player->get_board_ptr()->get_rows();
       y = rand() % player->get_board_ptr()->get_columns();

    }
    return new Move<char>(x, y, player->get_symbol());
}
