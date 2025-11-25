#ifndef BOARED_GAME_MEMORY_XO_UI_H
#define BOARED_GAME_MEMORY_XO_UI_H
#include "../../BoardGame_Classes.h"

class memory_XO_UI :public UI<char>
{
    public:
    memory_XO_UI();
    Player<char>* create_player(string &name, char symbol, PlayerType type) ;
    virtual Move <char>* get_move(Player<char>* player) ;
};


#endif //BOARED_GAME_MEMORY_XO_UI_H