#ifndef OBSTACLES_BOARD_H
#define OBSTACLES_BOARD_H
#include "../../BoardGame_Classes.h"
#include <vector>
class Obstacles_Board : public Board<char>
{
private:
    char blank_symbol = '.';
    int nombreMoves = 0;
public:
	Obstacles_Board();
    
    void addRandomObstacles(int n);

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>*) override { return false; };

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;
};

#endif 