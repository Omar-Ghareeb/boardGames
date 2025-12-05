#include "memory_XO_UI.h"

#include "memory_XO_board.h"
#include <windows.h>
#include <iostream>

using namespace std;
memory_XO_UI::memory_XO_UI() :UI<char>("Welcome to Memory XO ",3) {}
//creat players and take their name and type
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
//hide the real board by printing φ if the cell is not a blank cell
void memory_XO_UI::display_board_matrix(const vector<vector<char>>& matrix) const {
    if (matrix.empty() || matrix[0].empty()) return;
    SetConsoleOutputCP(CP_UTF8);
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\n    ";
    for (int j = 0; j < cols; ++j)
        cout << setw(cell_width + 1) << j;
    cout << "\n   " << string((cell_width + 2) * cols, '-') << "\n";

    for (int i = 0; i < rows; ++i) {
        cout << setw(2) << i << " |";
        //checks for blank cells to make a hidden board
        for (int j = 0; j < cols; ++j)
            cout << setw(cell_width) <<(matrix[i][j]=='.'?".":"  \u03C6") << " |";
        cout << "\n   " << string((cell_width + 2) * cols, '-') << "\n";
    }
    cout << endl;
}
