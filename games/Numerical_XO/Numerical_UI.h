#pragma once
#include "BoardGame_Classes.h"
using namespace std;

class Numerical_UI : public UI<int>
{
public:
    Numerical_UI();
    ~Numerical_UI() {};
    Player<int> *create_player(string &name, int numtype, PlayerType type);
    Player<int> **setup_players() override;
    virtual Move<int> *get_move(Player<int> *player) override;
};
