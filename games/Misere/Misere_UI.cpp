#include "Misere_UI.h"
#include <iostream>
#include <iomanip>
using namespace std;

Player<char>** Misere_UI::setup_players() {
    Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };

    string nameX = get_player_name("Player X");
    PlayerType typeX = get_player_type_choice("Player X", type_options);
    players[0] = create_player(nameX, static_cast<char>('X'), typeX);

    string nameO = get_player_name("Player O");
    PlayerType typeO = get_player_type_choice("Player O", type_options);
    players[1] = create_player(nameO, static_cast<char>('O'), typeO);

    players[0]->set_board_ptr(board);
    players[1]->set_board_ptr(board);

    return players;
}

void Misere_UI::display_board(Player<char>* loser)
{
    auto mb = dynamic_cast<Misere_Board*>(board);
    if (!mb) return;

    const int size = 3;
    const std::string death_msg = "DIED";

   
    std::cout << "       ";
    for (int c = 0; c < size; ++c) std::cout << c << "         ";
    std::cout << "\n";

    for (int r = 0; r < size; ++r) {
        std::cout << "   ---------------------------------\n";
        std::cout << " " << r << " |";

        for (int c = 0; c < size; ++c) {
            if (loser && r == 1 && c == 1) {  
                std::cout << loser->get_name() << " " << death_msg << " |";
            }
            else {
                std::cout << "   " << mb->get_cell(r, c) << "   |";
            }
        }

        std::cout << std::endl;
    }

    std::cout << "   ---------------------------------\n";
}

Player<char>* Misere_UI::create_player(string& name, char symbol, PlayerType type) {
    
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* Misere_UI::get_move(Player<char>* player) {
    int x, y;
    Board<char>* b = player->get_board_ptr();

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
    }

    else if (player->get_type() == PlayerType::COMPUTER) {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();

    }

    return new Move<char>(x, y, player->get_symbol());
}
