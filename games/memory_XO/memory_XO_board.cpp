#include "memory_XO_board.h"

#include "memory_XO_UI.h"
using namespace std;
memory_XO_board::memory_XO_board() : Board<char>(3,3) {
    // Initialize all cells in the board with blank_symbol
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j]= blank_symbol;
        }
    }
}

bool memory_XO_board::update_board(Move<char>* move) {
    int x=move->get_x();
    int y=move->get_y();
    char mark=move->get_symbol();

    // Validate move and apply if valid
    if (!(x<0 || x>=rows || y<0 || y>=columns) &&
        (board[x][y]==blank_symbol || mark==0)) {

        if (mark==0) { // Undo move
            n_moves--;
            board[x][y]=blank_symbol;
        }
        else {         // Apply move
            n_moves++;
            board[x][y]=toupper(mark);
        }
        return true;
        }
    return false;
}

bool memory_XO_board::is_win(Player<char>* player) {
    const char sym=player->get_symbol();
    auto all_equal = [&](char a, char b, char c) {
        return a==b && a==c && a!= blank_symbol;
    };
    //check rows and columns and if it's a win display the unhidden board
    for (int i = 0; i < rows; ++i) {
        if (all_equal(board[i][0],board[i][1],board[i][2])&& board[i][2]==sym||
            all_equal(board[0][i],board[1][i],board[2][i]) && board[2][i]==sym) {
            display_real_board();
            return true;
        }
    }
    //check diagonals and if it's a win display the unhidden board
    if (all_equal(board[0][0],board[1][1],board[2][2]) && board[2][2]==sym||
        all_equal(board[0][2],board[1][1],board[2][0]) && board[1][1]==sym) {
        display_real_board();
        return true;
    }

    return false;
}

bool memory_XO_board::is_draw(Player<char>* player) {
    //check if it's a draw if it is display the unhidden board
    if(n_moves==9 && !is_win(player))
        display_real_board();
    return (n_moves==9 && !is_win(player));
}

bool memory_XO_board::game_is_over(Player<char> *player) {
    return is_win(player)||is_draw(player);
}
//displays the unhidden board
void memory_XO_board::display_real_board() {
    int cell_width=3;
    cout << "\n    ";
    for (int j = 0; j < columns; ++j)
        cout << setw(4) << j;
    cout << "\n   " << string((cell_width + 2) * columns, '-') << "\n";

    for (int i = 0; i < rows; ++i) {
        cout << setw(2) << i << " |";
        for (int j = 0; j < columns; ++j)
            cout << setw(cell_width) <<board[i][j] << " |";
        cout << "\n   " << string((cell_width + 2) *columns, '-') << "\n";
    }
    cout << endl;
}



