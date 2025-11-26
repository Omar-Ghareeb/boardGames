#pragma once
#include "../../BoardGame_Classes.h"
#include <set>
#include <tuple>

class FiveXFive_Board : public Board<char>
{
private:
    char blank_symbol = '.';
    int player1_Score = 0;
    int player2_Score = 0;
    set<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> done;

public:
    FiveXFive_Board();
    bool update_board(Move<char> *move);
    bool is_win(Player<char> *player) { return false; }
    void plus(Player<char> *player);
    bool is_draw(Player<char> *player);
    bool is_lose(Player<char> *);
    bool game_is_over(Player<char> *player);
};
