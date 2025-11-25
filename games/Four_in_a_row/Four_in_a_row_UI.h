#ifndef BOARED_GAME_FOUR_IN_A_ROW_UI_H
#define BOARED_GAME_FOUR_IN_A_ROW_UI_H
#include "BoardGame_Classes.h"


class Four_in_a_row_UI :public UI<char>
{
    private:
        int available[7]={5,5,5,5,5,5,5};
    public:
    Four_in_a_row_UI();
    Player<char>* create_player(string& name, char symbol, PlayerType type);
    virtual Move<char>* get_move(Player<char>* player);

};


#endif //BOARED_GAME_FOUR_IN_A_ROW_UI_H