#pragma once
#include "../../BoardGame_Classes.h"
using namespace std;
class Ultimate_UI : public UI<char>
{
public:
    Ultimate_UI();

    ~Ultimate_UI() {};

    Player<char> *create_player(string &name, char symbol, PlayerType type);

    virtual Move<char> *get_move(Player<char> *player);
};
