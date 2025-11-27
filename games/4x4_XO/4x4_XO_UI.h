#pragma once
#include "BoardGame_Classes.h"
using namespace std;

class _4x4_XO_UI : public UI<char>
{
public:
    _4x4_XO_UI();
    ~_4x4_XO_UI() {};
    Player<char> *create_player(string &name, char symbol, PlayerType type);
    virtual Move<char> *get_move(Player<char> *player) override;
};
