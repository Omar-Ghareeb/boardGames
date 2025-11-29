#pragma once
#pragma once
#ifndef DIAMOND_UI_H
#define DIAMOND_UI_H

#include "../../BoardGame_Classes.h"
#include "Diamond_Board.h"
#include <iostream>

class Diamond_UI : public UI<char>
{
public:
    Diamond_UI() :UI<char>("Welcome to Diamond Tic Tac Toe", 11) {}

    ~Diamond_UI() {}

    virtual Move<char>* get_move(Player<char>* player);

    Player<char>* create_player(string& name, char symbol, PlayerType type);

   
};

#endif