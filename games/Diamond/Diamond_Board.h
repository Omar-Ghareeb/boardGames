#pragma once
#ifndef DIAMOND_BOARD_H
#define DIAMOND_BOARD_H
#include "../../BoardGame_Classes.h"
#include <vector>
class Diamond_Board : public Board<char>
{
private:
    char blank_symbol = '.';
    char invalid_symbol = ' ';
    int Moves = 0;
    vector<pair<int, int>> invalid = 
    {
            {0,0},{0,1}  ,{0,3},{0,4},
            {1,0}              ,{1,4},

            {3,0}              ,{3,4},
            {4,0},{4,1}  ,{4,3},{4,4}
    };
    
public:
    Diamond_Board();

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) override;

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;

    bool is_valid_cell(int x, int y);

    void check_direction(Player<char>* player, vector<vector<pair<int, int>>>& lines_3,
        vector<vector<pair<int, int>>>& lines_4) ;

    bool share_one_cell(const vector<pair<int, int>>& ligne3,
        const vector<pair<int, int>>& ligne4);

    bool same_direction(const vector<pair<int, int>>& a,
        const vector<pair<int, int>>& b);
};

#endif 