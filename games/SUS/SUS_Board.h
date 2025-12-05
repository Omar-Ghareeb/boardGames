#pragma once
#include "../../BoardGame_Classes.h"

using namespace std;

class SUS_Board : public Board<char>
{
private:
    char blank_symbol = '.';

public:
    SUS_Board();
    //count the number of SUS for player1
    int SUSPlayer1 = 0;
    //count the number of SUS for player2
    int SUSPlayer2 = 0;
    void checkNumOfSUS(char sym);
    bool update_board(Move<char> *move);
    bool is_win(Player<char> *player);
    bool is_draw(Player<char> *player);
    bool is_lose(Player<char> *player);
    bool game_is_over(Player<char> *player);
};
