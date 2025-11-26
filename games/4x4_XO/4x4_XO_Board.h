#pragma once
#include "BoardGame_Classes.h"
using namespace std;

class _4x4_XO_Board : public Board<char>
{
private:
    char blank_symbol = '.';

public:
    _4x4_XO_Board();

    bool update_board(Move<char> *move) override;
    bool is_win(Player<char> *player) override;
    bool is_lose(Player<char> *player) override { return false; }
    bool is_draw(Player<char> *player) override;
    bool game_is_over(Player<char> *player) override;
};
// GAMES_4X4_XO_4X4_XO_BOARD_H