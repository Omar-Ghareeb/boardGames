#pragma once
#ifndef MISERE_UI_H
#define MISERE_UI_H

#include "../../BoardGame_Classes.h"
#include "Misere_Board.h"
#include <iostream>

class Misere_UI : public UI<char> 
{
public: 
    Misere_UI() :UI<char>("Welcome to Misere Tic Tac Toe", 9) {}

    Misere_UI(Board<char>* b) :UI<char>("Welcome to Misere Tic Tac Toe", 9)
    {
        board = b;
    }

    ~Misere_UI() {}

    virtual Move<char>* get_move(Player<char>* player);

    Player<char>* create_player(string& name, char symbol, PlayerType type);

    Player<char>** setup_players() override;

    void display_board(Player<char>* loser);

private:
    Board<char>* board;
};

#endif


