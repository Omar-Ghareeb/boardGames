#include "memory_XO_UI.h"

#include "memory_XO_board.h"

using namespace std;
memory_XO_UI::memory_XO_UI() :UI<char>("Welcome to Memory XO ",3) {}

Player<char>* memory_XO_UI::create_player(string &name, char symbol, PlayerType type) {
    cout<<"Creating "<<(type == PlayerType::HUMAN ? "human":"computer")
        << " player: "<<name <<" ("<<symbol<<")\n";

    return new Player<char>(name, symbol, type);
}
Move<char>* memory_XO_UI::get_move(Player<char> *player) {
    int x,y;

    if (player->get_type()==PlayerType::HUMAN) {
        cout<<"\nPlease enter your move x and y (0 to 2): ";
        cin>>x>>y;
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        x=rand() % player->get_board_ptr()->get_rows();
        y=rand() % player->get_board_ptr()->get_columns();
    }
    return new Move<char>(x,y,player->get_symbol());
}
