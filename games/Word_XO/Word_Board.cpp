#include "WORD_BOARD.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;




Word_Board::Word_Board() : Board(3, 3) {
    // Initialize all cells with blank_symbol
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
}

bool Word_Board::update_board(Move<char>* move) {
    
    int x = move->get_x();
    int y = move->get_y();
    
    char mark = move->get_symbol();

    // Validate move and apply if valid
    if (!(x < 0 || x >= rows || y < 0 || y >= columns||mark<65||mark>122) &&
        (board[x][y] == blank_symbol || mark == 0)) {

        if (mark == 0) { // Undo move
            n_moves--;
            board[x][y] = blank_symbol;
        }
        else {         // Apply move
            n_moves++;
            board[x][y] = toupper(mark);
        }

        
        return true;
    }
    return false;
}

bool Word_Board::is_win(Player<char>* player) {
    ifstream MyReadFile("dic.txt");
    bool flag = true;
    string word;
    while (getline (MyReadFile, word)) {
        string word_rev = word;
        reverse(word_rev.begin(), word_rev.end());

        auto all_equal1 = [&](char a, char b, char c) {
             return a == word[0] && b == word[1] && c == word[2] && a != blank_symbol;
            };
        auto all_equal2 = [&](char a, char b, char c) {
             return a == word_rev[0] && b == word_rev[1] && c == word_rev[2] && a != blank_symbol;
            };

        // Check rows and columns
        for (int i = 0; i < rows; ++i) {
            if ((all_equal1(board[i][0], board[i][1], board[i][2]) || all_equal2(board[i][0],board[i][1],board[i][2])) ||
                (all_equal1(board[0][i], board[1][i], board[2][i]) || all_equal2(board[0][i],board[1][i],board[2][i]) ))
                return true;
        }

        // Check diagonals
        if ((all_equal1(board[0][0], board[1][1], board[2][2]) || all_equal2(board[0][0],board[1][1],board[2][2])) ||
            (all_equal1(board[0][2], board[1][1], board[2][0]) || all_equal2(board[0][2],board[1][1],board[2][0])))
            return true;

  
    }
    
    return false;
}

bool Word_Board::is_draw(Player<char>* player) {
    return (n_moves == 9 && !is_win(player));
}

bool Word_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}