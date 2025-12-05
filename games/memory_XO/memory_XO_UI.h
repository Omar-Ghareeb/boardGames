#pragma once
#include "../../BoardGame_Classes.h"

class memory_XO_UI : public UI<char>
{
public:
    memory_XO_UI();
    Player<char> *create_player(string &name, char symbol, PlayerType type);
    virtual Move<char> *get_move(Player<char> *player);
    virtual void display_board_matrix(const vector<vector<char>>& matrix) const;
};
