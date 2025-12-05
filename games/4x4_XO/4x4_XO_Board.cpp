#include "4x4_XO_Board.h"
using namespace std;

_4x4_XO_Board::_4x4_XO_Board() : Board<char>(4, 4)
{ // 4x4 board
    // Initialize the board with blank symbols (.)
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            board[r][c] = blank_symbol;
        }
    }
}

bool _4x4_XO_Board::update_board(Move<char> *move)
{
    int r = move->get_x();
    int c = move->get_y();
    char symbol = move->get_symbol();

    if (r < 0 || r >= rows || c < 0 || c >= columns)
    {
        cout << "Move out of bounds. Try again.\n";
        return false;
    }

    // Check if the cell is empty
    if (board[r][c] != blank_symbol)
    {
        cout << "Cell is already occupied. Try again.\n";
        return false;
    }

    // Place the symbol on the board
    board[r][c] = symbol;
    n_moves++;
    return true;
}

bool _4x4_XO_Board::is_win(Player<char> *player)
{
    char sym = player->get_symbol();

    // Check rows
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (board[i][j] == sym &&
                board[i][j + 1] == sym &&
                board[i][j + 2] == sym)
                return true;
        }
    }

    // Check columns
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <= 1; i++)
        {
            if (board[i][j] == sym &&
                board[i + 1][j] == sym &&
                board[i + 2][j] == sym)
                return true;
        }
    }

    // main diagonal
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (board[i][j] == sym &&
                board[i + 1][j + 1] == sym &&
                board[i + 2][j + 2] == sym)
                return true;
        }
    }

    // anti-diagonal
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 2; j < 4; j++)
        { // starting at column 2 or 3
            if (board[i][j] == sym &&
                board[i + 1][j - 1] == sym &&
                board[i + 2][j - 2] == sym)
                return true;
        }
    }

    return false;
}

bool _4x4_XO_Board::is_draw(Player<char> *player)
{
    return n_moves >= 16 && !is_win(player);
}

bool _4x4_XO_Board::game_is_over(Player<char> *player)
{
    return is_win(player) || is_draw(player);
}
