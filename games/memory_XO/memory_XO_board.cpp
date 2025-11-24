#include "memory_XO_board.h"

#include "memory_XO_UI.h"
using namespace std;
memory_XO_board::memory_XO_board() : Board<char>(3,3) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j]= blank_symbol;
            matrix[i][j]= blank_symbol;
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
            matrix[x][y]=blank_symbol;
        }
        else {         // Apply move
            n_moves++;
            board[x][y]='Q';
            matrix[x][y]=toupper(mark);
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

    for (int i = 0; i < rows; ++i) {
        if (all_equal(matrix[i][0],matrix[i][1],matrix[i][2])&& matrix[i][2]==sym||
            all_equal(matrix[0][i],matrix[1][i],matrix[2][i]) && matrix[2][i]==sym) {
            return true;
        }
    }

    if (all_equal(matrix[0][0],matrix[1][1],matrix[2][2]) && matrix[2][2]==sym||
        all_equal(matrix[0][2],matrix[1][1],matrix[2][0]) && matrix[1][1]==sym) {
        return true;
    }

    return false;
}

bool memory_XO_board::is_draw(Player<char>* player) {
    return (n_moves==9 && !is_win(player));
}

bool memory_XO_board::game_is_over(Player<char> *player) {
    return is_win(player)||is_draw(player);
}


