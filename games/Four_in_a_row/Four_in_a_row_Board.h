#ifndef BOARED_GAME_FOUR_IN_A_ROW_BOARD_H
#define BOARED_GAME_FOUR_IN_A_ROW_BOARD_H
#include"../../BoardGame_Classes.h"


class Four_in_a_row_Board :public Board<char>
{
    private:
        char blank_symbol='.';
    public:
        Four_in_a_row_Board();
        bool update_board(Move<char>* move);
        bool is_win(Player<char>* player);
        bool is_draw(Player<char>* player) ;
        bool is_lose(Player<char> *){return false;}
        bool game_is_over(Player<char>* player);

};


#endif //BOARED_GAME_FOUR_IN_A_ROW_BOARD_H