#ifndef NUMERICAL_BOARD_H
#define NUMERICAL_BOARD_H
#include "BoardGame_Classes.h"
#include <vector>
#include <algorithm>
using namespace std;

class Numerical_Board : public Board<int> {
private:
    vector<int> remaining_odd={1,3,5,7,9};
    vector<int> remaining_even={2,4,6,8};
    int blank_symbol=0;

public:
    Numerical_Board();

    bool update_board(Move<int>* move) override;
    bool is_win(Player<int>* player) override;
    bool is_lose(Player<int>* player) override {
        return false; // No losing condition in Numerical XO
    }
    bool is_draw(Player<int>* player) override;
    bool game_is_over(Player<int>* player) override;

    int line_sum(int r0,int c0,int r1,int c1,int r2,int c2);

    bool is_number_available(int number, int numtype);
    void use_number(int number, int numtype);

    vector<int>& get_remaining_odd(){return remaining_odd;}
    vector<int>& get_remaining_even(){return remaining_even;}

    int get_cell_symbol(int r, int c){
        return board[r][c];
    }
};
#endif // NUMERICAL_BOARD_H