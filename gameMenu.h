#ifndef gameMenu.h
#define gameMenu.h
#include "games/Infinity_XO/Infinity_Board.h"
#include "games/Infinity_XO/Infinity_UI.h"
#include "games/SUS/SUS_Board.h"
#include "games/SUS/SUS_UI.h"
using namespace std;
template <typename T>
void cleanMem(UI<T>* ui,Board<T>* board, Player<T>** players){
    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
    delete[] players;
    delete ui;
}
void runInfinity(){
    UI<char>* game_ui = new Infinity_UI();
    Board<char>* Infinity_board = new infinity_Board();
    Player<char>** players = game_ui->setup_players();
    GameManager<char> Infinity_game(Infinity_board, players, game_ui);
    Infinity_game.run();
    cleanMem(game_ui,Infinity_board,players);
}

void runSUS() {
    UI<char>* SUS_ui = new SUS_UI();
    Board<char>* SUS_board = new SUS_Board();
    Player<char>** SUS_players = SUS_ui->setup_players();
    GameManager<char> SUS_game(SUS_board, SUS_players, SUS_ui);
    SUS_game.run();
    cleanMem(SUS_ui,SUS_board,SUS_players);
}
#endif