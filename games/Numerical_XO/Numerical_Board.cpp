#include "Numerical_Board.h"
#include <iostream>
using namespace std;

Numerical_Board::Numerical_Board() : Board<int>(3, 3)
{
    // Initialize the board with blank symbols (0)
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            board[r][c] = blank_symbol;
        }
    }
}

bool Numerical_Board::update_board(Move<int> *move)
{
    int r = move->get_x();
    int c = move->get_y();
    int symbol = move->get_symbol();

    // Place the integer on the board
    board[r][c] = symbol;
    n_moves++;
    return true;
}

int Numerical_Board::line_sum(int r0, int c0, int r1, int c1, int r2, int c2)
{
    return board[r0][c0] + board[r1][c1] + board[r2][c2]; // sum of three cells
}

bool Numerical_Board::is_win(Player<int> *player)
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i)
    {
        // Check Row i: Sum must be 15 AND product must not be 0 (ensures no empty cells)
        if ((line_sum(i, 0, i, 1, i, 2) == 15 && board[i][0] * board[i][1] * board[i][2] != 0) ||
            // Check Column i
            (line_sum(0, i, 1, i, 2, i) == 15 && board[0][i] * board[1][i] * board[2][i] != 0))
        {
            return true;
        }
    }
    // Check Main Diagonal
    if ((line_sum(0, 0, 1, 1, 2, 2) == 15 && board[0][0] * board[1][1] * board[2][2] != 0) ||
        // Check Anti-Diagonal
        (line_sum(0, 2, 1, 1, 2, 0) == 15 && board[0][2] * board[1][1] * board[2][0] != 0))
    {
        return true;
    }
    return false;
}

bool Numerical_Board::is_draw(Player<int> *player)
{
    return n_moves >= 9 && !is_win(player);
}

bool Numerical_Board::game_is_over(Player<int> *player)
{
    return is_win(player) || is_draw(player);
}

bool Numerical_Board::is_number_available(int number, int numtype)
{
    if (numtype == 0)
    { // Odd
        return find(remaining_odd.begin(), remaining_odd.end(), number) != remaining_odd.end();
    }
    else
    { // Even
        return find(remaining_even.begin(), remaining_even.end(), number) != remaining_even.end();
    }
}

void Numerical_Board::use_number(int number, int numtype)
{
    // Finds and removes the used number from the respective vector
    if (numtype == 0)
    { // Odd
        remaining_odd.erase(remove(remaining_odd.begin(), remaining_odd.end(), number), remaining_odd.end());
    }
    else
    { // Even
        remaining_even.erase(remove(remaining_even.begin(), remaining_even.end(), number), remaining_even.end());
    }
}