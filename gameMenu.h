#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "games/Infinity_XO/Infinity_Board.h"
#include "games/Infinity_XO/Infinity_UI.h"

#include "games/Obstacles_Tic-Tac-Toe/Obstacles_UI.h"
#include "games/Obstacles_Tic-Tac-Toe/Obstacles_Board.h"

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
void runInfinity()
{
    UI<char>* game_ui = new Infinity_UI();

    Board<char>* Infinity_board = new infinity_Board();

    Player<char>** players = game_ui->setup_players();

    GameManager<char> Infinity_game(Infinity_board, players, game_ui);

    Infinity_game.run();

    cleanMem(game_ui, Infinity_board, players);
}

void runInObstacles()
{
    UI<char>* game_ui = new Obstacles_UI();

    Board<char>* board = new Obstacles_Board();

    Player<char>** players = game_ui->setup_players();

    GameManager<char> Obstacles_game(board, players, game_ui);

    Obstacles_game.run();

    cleanMem(game_ui, board, players);
}
#endif