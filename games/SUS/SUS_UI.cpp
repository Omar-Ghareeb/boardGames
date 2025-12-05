#include "SUS_UI.h"
using namespace std;

SUS_UI::SUS_UI() :UI<char>("Welcome to SUS game",3){}

Player<char> **SUS_UI::setup_players() {
       Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };
    // override players and their symbols to be S and U
    string nameX = get_player_name("Player S");
    PlayerType typeX = get_player_type_choice("Player S", type_options);
    players[0] = create_player(nameX, static_cast<char>('S'), typeX);

    string nameO = get_player_name("Player U");
    PlayerType typeO = get_player_type_choice("Player U", type_options);
    players[1] = create_player(nameO, static_cast<char>('U'), typeO);

    return players;
}

Player<char>* SUS_UI::create_player(string& name, char symbol, PlayerType type) {

    cout<<"Creating "<<(type==PlayerType::HUMAN?"human":"computer")
    <<" player: "<<name<<" ("<<symbol<< ")\n";

    return new Player<char>(name, symbol, type);
}
Move<char>* SUS_UI::get_move(Player<char>* player) {
    int x,y;

    if (player->get_type()==PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        x=rand()% player->get_board_ptr()->get_rows();
        y=rand()% player->get_board_ptr()->get_columns();
    }
    return new Move<char>(x, y, player->get_symbol());
}
