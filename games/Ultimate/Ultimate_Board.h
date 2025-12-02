#pragma once
#include "../../BoardGame_Classes.h"
#include <cstring>

using namespace std;
class Ultimate_Board : public Board<char>
{
private:
    char blank_symbol = '.'; // basic blank symbol
    int NoOfCompletedBoard = 0;
    char boards[3][3];

public:
    // default constructor
    Ultimate_Board();
    void MiniGridDOne(char sym);
    bool update_board(Move<char> *move);
    bool is_win(Player<char> *player);
    bool is_lose(Player<char> *) { return false; };
    bool is_draw(Player<char> *player);
    bool game_is_over(Player<char> *player);
};
