#ifndef MISERE_BOARD_H
#define MISERE_BOARD_H
#include "../../BoardGame_Classes.h"
class Misere_Board : public Board<char>
{
private:
    char blank_symbol = '.';
    int Moves = 0;
    
public:
    Misere_Board();

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) override;

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;

    char get_cell(int r, int c) const { return board[r][c]; }

  
};

#endif 