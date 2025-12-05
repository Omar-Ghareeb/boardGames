#include "SUS_Board.h"
using namespace std;

SUS_Board::SUS_Board() : Board<char>(3,3) {
    // Initialize all cells with blank_symbol
    for (auto& row :board)
        for (auto& cell : row)
            cell=blank_symbol;
}

bool SUS_Board::update_board(Move<char> *move) {
    int x=move->get_x();
    int y=move->get_y();
    char mark=move->get_symbol();

    // Validate move and apply if valid
    if (!(x < 0 || x >= rows || y < 0 || y >= columns) &&
        (board[x][y] == blank_symbol || mark == 0))  {

        if (mark==0) {
            n_moves--;
            board[x][y] = blank_symbol;
        }
        else {
            n_moves++;
            board[x][y] = toupper(mark);
            //update number of SUS on board after every move
            checkNumOfSUS(board[x][y]);
        }
        return true;
    }
     return false;
}

void SUS_Board::checkNumOfSUS(char sym) {
    //get the number os SUS in the board
    int numOfSUS=0;
    auto all_equal=[&](char a,char b,char c) {
        return (a=='S' && b=='U' && c=='S');
    };
    // get all SUS in the board

    //check for SUS in rows and columns
    for (int i=0 ;i<rows;i++) {
        if (all_equal(board[i][0],board[i][1],board[i][2]))
            numOfSUS++;
        if(all_equal(board[0][i],board[1][i],board[2][i]))
            numOfSUS++;
    }
         //check for SUS in diagonals
        if (all_equal(board[0][0],board[1][1],board[2][2]))
            numOfSUS++;
        if(all_equal(board[0][2],board[1][1],board[2][0]))
            numOfSUS++;

    /*update the number of SUS for the current player
     *get all SUS in the board and subtract the number of SUS for the other player
     ex: if player1 has 1 SUS and player2 has 0 SUS and number of SUS in the board is 2
     then the current player added 1 SUS to the board*/
    if (sym=='S')
        SUSPlayer1=numOfSUS-SUSPlayer2;
    else
        SUSPlayer2=numOfSUS-SUSPlayer1;
}


bool SUS_Board::is_win(Player<char>* player ) {
    if (n_moves==9) {
       //the last player will be player1 check if they win
       if ( SUSPlayer1>SUSPlayer2)
           return true;
    }
    return false;
}

bool SUS_Board::is_lose(Player<char> *player) {
    if (n_moves==9) {
        //the last player will be player1 check if they lose
        if (SUSPlayer1<SUSPlayer2)
            return true;
    }
    return false;
}


bool SUS_Board::is_draw(Player<char> *player) {
    return (n_moves == 9 && SUSPlayer1==SUSPlayer2);
}

bool SUS_Board::game_is_over(Player<char> *player) {
    return is_win(player) || is_draw(player);
}
