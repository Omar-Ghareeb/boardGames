#include "Numerical_UI.h"
#include "Numerical_Board.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Numerical_UI::Numerical_UI() : UI<int>("Welcome to Numerical X-O",3) {}

Player<int>** Numerical_UI::setup_players() {
    const vector<string> player_type_options = { "Human", "Computer" };
    Player<int>** players = new Player<int>*[2];

    string name = get_player_name("Player 1");
    PlayerType type = get_player_type_choice("Player 1", player_type_options);
    int numtype = 0; // 0 for Odd
    players[0] = create_player(name, numtype, type);

    name = get_player_name("Player 2");
    type = get_player_type_choice("Player 2", player_type_options);
    numtype = 1; // 1 for Even
    players[1] = create_player(name, numtype, type);

    return players;
}

Player<int>* Numerical_UI::create_player(string& name, int numtype, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << (numtype == 0 ? "Odd" : "Even") << ")\n";

    return new Player<int>(name, numtype, type);
}

Move<int>* Numerical_UI::get_move(Player<int>* player) {
    int x, y, number;
    Numerical_Board* board = dynamic_cast<Numerical_Board*>(player->get_board_ptr()); // Create a pointer to the Numerical_Board

    // Get available numbers based on type
    vector<int> available;
    if (player->get_symbol() == 0) available = board->get_remaining_odd();
    else available = board->get_remaining_even();

    if (player->get_type() == PlayerType::HUMAN){
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;

        while (true) {
            if (x < 0 || x >= player->get_board_ptr()->get_rows() ||
                y < 0 || y >= player->get_board_ptr()->get_columns()) {
                cout << "Invalid position! Try again.\n";
                cout << "Please enter your move x and y (0 to 2): ";
                cin >> x >> y;
            } else if (board->get_cell_symbol(x, y) != 0) {
                cout << "Cell already occupied! Try again.\n";
                cout << "Please enter your move x and y (0 to 2): ";
                cin >> x >> y;
            } else {
                break; // valid position
            }
        }

        // Display available numbers
        cout << "Available numbers: ";
        for (int n : available) cout << n << " ";
        cout << endl;

        // Ask for a number until valid
        do {
            cout << "Enter your number: ";
            cin >> number;
            if (!board->is_number_available(number, player->get_symbol()))
                cout << "Number not available! Try again.\n";
        } while (!board->is_number_available(number, player->get_symbol()));
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        // pick random valid number
        number = available[rand() % available.size()];

        // pick random valid position
        x=rand()% player->get_board_ptr()->get_rows();
        y=rand()% player->get_board_ptr()->get_columns();
    }

    board->use_number(number, player->get_symbol()); // remove the number from remaining numbers based on type

    return new Move<int>(x, y, number);
}