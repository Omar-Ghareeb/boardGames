#ifndef BOARED_GAME_SUS_BOARD_H
#define BOARED_GAME_SUS_BOARD_H
#include<BoardGame_Classes.h>

using namespace std;

class SUS_Board :public Board<char> {
private:
    char blank_symbol='.';

public:
    SUS_Board();
    int SUSPlayer1=0;
    int SUSPlayer2=0;
    void checkNumOfSUS(char sym);
    bool update_board(Move<char> *move);
    bool is_win(Player<char>* player);
    bool is_draw(Player<char>* player);
    bool is_lose(Player<char>* player) ;
    bool game_is_over(Player<char>* player);
};


#endif //BOARED_GAME_SUS_BOARD_H