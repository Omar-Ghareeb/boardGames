#ifndef WORD_UI_H
#define WORD_ui_H
#include "../../BoardGame_Classes.h"
using namespace std;
class Word_UI : public UI<char> {
public:
    Word_UI();
    ~Word_UI() {};
    Player<char>* create_player(string& name, char symbol, PlayerType type);
    Player<char>** setup_players() override;
    virtual Move<char>* get_move(Player<char>* player);
    
};
#endif