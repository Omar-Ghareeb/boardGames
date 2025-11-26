#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;

class SUS_UI : public UI<char>
{
public:
    SUS_UI();
    ~SUS_UI() {};
    Player<char> *create_player(string &name, char symbol, PlayerType type);
    Player<char> **setup_players() override;
    virtual Move<char> *get_move(Player<char> *player);
};
