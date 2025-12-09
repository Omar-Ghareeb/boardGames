#include "Obstacles_Board.h"
#include <vector>
using namespace std;

Obstacles_Board::Obstacles_Board() : Board(6, 6)
{
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
}
void Obstacles_Board::addRandomObstacles(int n)
{

    int added = 0;
    while (added < n)
    {
        int r = rand() % 6;
        int c = rand() % 6;
        
            if (board[r][c] == blank_symbol)
            {
                board[r][c] = '#';
                added++;
                nombreMoves ++;
            }
        
    }
}
bool Obstacles_Board::update_board(Move<char>* move)
{
    int row = move->get_x();
    int col = move->get_y();

    if (row < 0 || row >= 6 || col < 0 || col >= 6) return false;

    if (board[row][col] != blank_symbol) return false;

    board[row][col] = move->get_symbol();

    nombreMoves++;

    if (nombreMoves % 2 == 0) addRandomObstacles(2);

    return true;

}

bool Obstacles_Board::is_win(Player<char>* player)
{
    char s = player->get_symbol();
   
    //Horizontale
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == s && board[row][col + 1]==s && 
                board[row][col + 2] ==s && board[row][col + 3]==s) return true;
         }
    }
    //Verticale
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            if (board[row][col] == s && board[row+1][col]==s && board[row+2][col]==s && 
                board[row+3][col]==s) return true;
        }
    }
    //Diagonale vers le haut
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == s && board[row+1][col + 1]==s && board[row+2][col + 2] ==s
                && board[row+3][col + 3]==s) return true;
        }
    }
    //Diogonale vers le bas
    for (int row = 3; row < 6; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == s && board[row-1][col + 1]==s &&
                board[row-2][col + 2] ==s && board[row-3][col + 3]==s ) return true;
        }
    }

    return false;
}

bool Obstacles_Board::is_draw(Player<char>* player)
{
    return nombreMoves >= 36 && !is_win(player);
}

bool Obstacles_Board::game_is_over(Player<char>* player)
{
    return is_win(player) || is_draw(player);
}
