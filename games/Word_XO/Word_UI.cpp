#include "WORD_UI.h"
#include <random>
using namespace std;

Word_UI::Word_UI() : UI<char>("Welcome to Word XO", 3) {}


Player<char> **Word_UI::setup_players() {
       Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };

    string name1 = get_player_name("Player 1");
    PlayerType type1 = get_player_type_choice("Player 1", type_options);
    players[0] = create_player(name1, static_cast<char>('1'), type1);

    string name2 = get_player_name("Player 2");
    PlayerType type2 = get_player_type_choice("Player 2", type_options);
    players[1] = create_player(name2, static_cast<char>('2'), type2);

    return players;
}
Player<char>* Word_UI::create_player(string& name, char symbol, PlayerType type) {
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* Word_UI::get_move(Player<char>* player) {
    int x, y;
    char s;
    
    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
        cout<< "\n Please enter the letter u want to play";
        cin>>s;
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
        random_device rd;
        mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(97, 122);
        s = distrib(gen);
    }
    return new Move<char>(x, y, s);
}
