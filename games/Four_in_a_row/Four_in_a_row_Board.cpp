#include "Four_in_a_row_Board.h"

Four_in_a_row_Board::Four_in_a_row_Board() :Board<char>(6,7) {
    for (auto& row :board)
        for (auto& cell :row)
            cell = blank_symbol;
}

bool Four_in_a_row_Board::update_board(Move<char> *move) {
    int x = move->get_x();
    int y = move->get_y();
    char mark=move->get_symbol();

    if (!(x < 0 || x >= rows || y < 0 || y >= columns) &&
    (board[x][y] == blank_symbol || mark == 0) && available[y]==x &&available[y]>=0) {

        if (mark == 0) { // Undo move
            n_moves--;
            board[x][y] = blank_symbol;
        }
        else {         // Apply move
            n_moves++;
            board[x][y] = toupper(mark);
            available[y]--;
        }
        return true;
    }
    return false;
}

bool Four_in_a_row_Board::is_win(Player<char> *player) {
    const char sym=player->get_symbol();
    auto all_equal=[&](char a,char b, char c,char d) {
        return a==b && b==c && c==d && a!=blank_symbol;
    };

    // Check rows
    for (int row=5; row>=0;--row){
        for (int col=0;col<4; ++col) {
            if (all_equal(board[row][col],board[row][col+1],board[row][col+2],board[row][col+3])&&board[row][col]==sym)
                return true;
        }
    }

    //Check columns
    for (int col=0;col<7; ++col) {
        for (int row=5;row>=3;--row) {
            if (all_equal(board[row][col],board[row-1][col],board[row-2][col],board[row-3][col])&&board[row][col]==sym)
                return true;
        }
    }
    //check diagonal
    for (int row=5;row>=3;--row) {
        for (int col=6;col>=3;--col) {
            if (all_equal(board[row][col],board[row-1][col-1],board[row-2][col-2],board[row-3][col-3])&&board[row][col]==sym)
                return true;
        }
    }
    for (int row=5;row>=3;--row) {
        for (int col=0;col<4;++col) {
            if (all_equal(board[row][col],board[row-1][col-1],board[row-2][col+2],board[row-3][col+3])&&board[row][col]==sym)
                return true;
        }
    }
    return false;
}

bool Four_in_a_row_Board::is_draw(Player<char> *player) {
    return (n_moves ==42 &&!is_win(player));
}

bool Four_in_a_row_Board::game_is_over(Player<char> *player) {
    return(is_win(player)||is_draw(player));
}
