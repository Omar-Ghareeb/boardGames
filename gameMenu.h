#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "games/Infinity_XO/Infinity_Board.h"
#include "games/Infinity_XO/Infinity_UI.h"


#include "games/Obstacles_Tic-Tac-Toe/Obstacles_UI.h"
#include "games/Obstacles_Tic-Tac-Toe/Obstacles_Board.h"

#include "games/SUS/SUS_Board.h"
#include "games/SUS/SUS_UI.h"


#include "games/Word_XO/Word_UI.h"
#include "games/Word_XO/Word_Board.h"

#include "games/memory_XO/memory_XO_board.h"
#include "games/memory_XO/memory_XO_UI.h"

#include "games/Numerical_XO/Numerical_Board.h"
#include "games/Numerical_XO/Numerical_UI.h"

#include "games/4x4_XO/4x4_XO_Board.h"
#include "games/4x4_XO/4x4_XO_UI.h"

#include "games/Pyramid_XO/Pyramid_Board.h"
#include "games/Pyramid_XO/Pyramid_UI.h"

#include "games/Four_in_a_row/Four_in_a_row_Board.h"
#include "games/Four_in_a_row/Four_in_a_row_UI.h"

#include "games/Misere/Misere_Board.h"
#include "games/Misere/Misere_UI.h"


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
void runMisere()
{
    Misere_Board* board = new Misere_Board();

    Misere_UI* game_ui = new Misere_UI(board);

    Player<char>** players = game_ui->setup_players();

    GameManager<char> Misere_game(board, players, game_ui);

    Misere_game.run();

    Player<char>* loser = nullptr;
    for (int i = 0; i < 2; ++i) {
        if (board->is_lose(players[i])) {
            loser = players[i];
            break;
        }
    }

    // Display the final board with the death message
    if (loser) {
        game_ui->display_board(loser);
    }
    else {
        game_ui->display_board(nullptr); // or normal board display
    }

    cleanMem(game_ui, board, players);
}


void runSUS() {
    UI<char>* SUS_ui = new SUS_UI();
    Board<char>* SUS_board = new SUS_Board();
    Player<char>** SUS_players = SUS_ui->setup_players();
    GameManager<char> SUS_game(SUS_board, SUS_players, SUS_ui);
    SUS_game.run();
    cleanMem(SUS_ui,SUS_board,SUS_players);
}
void runWord(){
    UI<char>* Word_ui = new Word_UI();
    Board<char>* Word_board = new Word_Board();
    Player<char>** Word_players = Word_ui->setup_players();
    GameManager<char> Word_game(Word_board, Word_players, Word_ui);
    Word_game.run();
    cleanMem(Word_ui,Word_board,Word_players);
}
void runMemoryXO() {
    UI<char>* game_ui = new memory_XO_UI();
    Board<char>* memory_xo_board = new memory_XO_board();
    Player<char>** players = game_ui->setup_players();
    GameManager<char> memory_xo_game(memory_xo_board,players,game_ui);
    memory_xo_game.run();
    cleanMem(game_ui,memory_xo_board,players);
}
#endif