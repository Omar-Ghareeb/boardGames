#pragma once
#include "../../BoardGame_Classes.h"
#include <queue>
using namespace std;
class Word_Board : public Board<char>
{
private:
    char blank_symbol = '.'; // basic blank symbol

public:
    // default constructor
    Word_Board();

    bool update_board(Move<char> *move);
    bool is_win(Player<char> *player);
    bool is_lose(Player<char> *) { return false; };
    bool is_draw(Player<char> *player);
    bool game_is_over(Player<char> *player);
};
