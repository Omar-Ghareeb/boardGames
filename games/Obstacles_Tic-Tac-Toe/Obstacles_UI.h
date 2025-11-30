#pragma once

#include "../../BoardGame_Classes.h"
#include "Obstacles_Board.h"
#include <iostream>

class Obstacles_UI : public UI<char>
{
public:
    Obstacles_UI();

    ~Obstacles_UI() {}

    virtual Move<char> *get_move(Player<char> *player);

    Player<char> *create_player(string &name, char symbol, PlayerType type);
};
