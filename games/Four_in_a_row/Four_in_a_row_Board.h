#pragma once
#include "../../BoardGame_Classes.h"

class Four_in_a_row_Board : public Board<char>
{
private:
    char blank_symbol = '.';
    int available[7] = {5, 5, 5, 5, 5, 5, 5};

public:
    Four_in_a_row_Board();
    bool update_board(Move<char> *move);
    bool is_win(Player<char> *player);
    bool is_draw(Player<char> *player);
    bool is_lose(Player<char> *) { return false; }
    bool game_is_over(Player<char> *player);
};
