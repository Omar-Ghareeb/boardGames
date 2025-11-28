#include "Misere_Board.h"

Misere_Board::Misere_Board() :Board(3,3)
{
	for (auto& row : board)
		for (auto& cell : row)
			cell = blank_symbol;
}

bool Misere_Board::update_board(Move<char>* move)
{
	int row = move->get_x();
	int col = move->get_y();

	if (row < 0 || row >= 3 || col < 0 || col >= 3) return false;

	if (board[row][col] != blank_symbol) return false;

	board[row][col] = move->get_symbol();

	Moves++;

	return true;

}

bool Misere_Board::is_win(Player<char>* player)
{
	return false;
}

bool Misere_Board::is_lose(Player<char>* player)
{
    char s = player->get_symbol();
  
    ////Diogonale vers le bas
    //  00 01 02
    //  10 11 12
    //  20 21 22
    for (int r = 0; r < 3; r++)
        if (board[r][0] == s && board[r][1] == s && board[r][2] == s)
        {
            return true;
        }

    // Columns
    for (int c = 0; c < 3; c++)
        if (board[0][c] == s && board[1][c] == s && board[2][c] == s)
        {
            return true;
        }
       
    //Diogonale vers le bas
       if (board[0][0] == s && board[1][1] == s && board[2][2] == s )
       {
           return true;
       }
       
    //Diagonale vers le haut
    if (board[0][2] == s && board[1][ 1] == s && board[2][0] == s)
    {
        return true;
    }
        
	return false;
}

bool Misere_Board::is_draw(Player<char>* player)
{
    return Moves == 9 && !is_lose(player);
}

bool Misere_Board::game_is_over(Player<char>* player)
{
	return  is_lose(player) || is_draw(player);
}
