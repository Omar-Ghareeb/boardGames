#ifndef BOARED_GAME_MEMORY_XO_BOARD_H
#define BOARED_GAME_MEMORY_XO_BOARD_H
#include "../../BoardGame_Classes.h"
using namespace std;
#include<vector>
class memory_XO_board :public Board<char>
{
    private:
    char blank_symbol='.';
    char matrix[3][3];
    public:
    memory_XO_board();
    bool update_board(Move<char>* move);
    bool is_win(Player<char>* player);
    bool is_lose(Player<char>* ) { return false;} ;
    bool is_draw(Player<char>* player) ;
    bool game_is_over(Player<char>* player);
};


#endif //BOARED_GAME_MEMORY_XO_BOARD_H