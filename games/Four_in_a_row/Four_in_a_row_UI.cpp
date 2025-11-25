#include "Four_in_a_row_UI.h"

Four_in_a_row_UI::Four_in_a_row_UI():UI<char>( "Welcome to Four in a row game",3){}

Player<char>* Four_in_a_row_UI::create_player(string &name, char symbol, PlayerType type) {
    cout<<"Creating "<<(type==PlayerType::HUMAN?"human":"computer")
<<" player: "<<name<<" ("<<symbol<< ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* Four_in_a_row_UI::get_move(Player<char>* player) {
    int x,y;

    if (player->get_type()==PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y : ";
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        x= available[rand()%7];
        y=rand()% player->get_board_ptr()->get_columns();
    }
    if (available[y]>=0 && available[y]==x && x<player->get_board_ptr()->get_rows()
        && y<player->get_board_ptr()->get_columns() && x>=0 && y>=0)
        available[y]--;
    return new Move<char>(x, y, player->get_symbol());
}

