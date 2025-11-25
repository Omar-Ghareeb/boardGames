#include "Pyramid_UI.h"
#include "Pyramid_Board.h"
#include <iostream>
using namespace std;

Pyramid_XO_UI::Pyramid_XO_UI() :UI<char>("Welcome to Pyramid X-O", 3) {} 

Player<char>* Pyramid_XO_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* Pyramid_XO_UI::get_move(Player<char>* player) {
    int x=-1, y=-1;

    Pyramid_Board* board = dynamic_cast<Pyramid_Board*>(player->get_board_ptr());

    if (player->get_type() == PlayerType::HUMAN) {;
         do {
            cout << "\nPlease enter your move x and y (within the pyramid): ";
            cin >> x >> y;
            if (!board->is_valid_cell(x, y)) {
                cout << "That cell is not part of the pyramid. Try again.\n";
                x = y = -1;
            } else if (board->get_cell(x, y) != '.') {
                cout << "That cell is already occupied. Try again.\n";
                x = y = -1;
            }
        } while (x == -1);
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        x = rand() % player->get_board_ptr()->get_rows();
        if(x==0){
            y=2;
        }
        else if(x==1){
            y=1+rand()%3;
        }
        else if(x==2){
            y=rand()%5;
        }
    }
    return new Move<char>(x, y, player->get_symbol());
}