#include "5X5_Board.h"
using namespace std;

FiveXFive_Board::FiveXFive_Board() : Board(5, 5)
{
    // Initialize all cells with blank_symbol
    for (auto &row : board)
        for (auto &cell : row)
            cell = blank_symbol;
}

void FiveXFive_Board::plus(Player<char> *player)
{
    const char sym = toupper(player->get_symbol());

    // Lambda: Check if three cells contain the same symbol (and aren't empty)
    auto all_equal = [&](char a, char b, char c)
    {
        return (a == b && b == c && a != blank_symbol);
    };

    // Lambda: Check if this specific set of coordinates has been counted before
    auto not_yet_counted = [&](pair<int, int> a, pair<int, int> b, pair<int, int> c)
    {
        pair<int, int> v1, v2, v3;
        bool f1 = 0, f2 = 0, f3 = 0;

        // Iterate through the 'done' set to see if this triplet exists
        for (auto i : done)
        {
            tie(v1, v2, v3) = i;
            // Check matching logic
            f1 = (a == v1 || a == v2 || a == v3);
            f2 = (b == v1 || b == v2 || b == v3);
            f3 = (c == v1 || c == v2 || c == v3);
            if (f1 && f2 && f3)
            {
                break; // Found a match, already counted
            }
            else
            {
                f1 = 0;
                f2 = 0;
                f3 = 0;
            }
        }
        return !(f1 && f2 && f3); // Return true if NOT found (safe to count)
    };

    // Check rows and columns for new sequences of 3
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            // Check Horizontal
            if ((all_equal(board[i][j], board[i][j + 1], board[i][j + 2]) && not_yet_counted({i, j}, {i, j + 1}, {i, j + 2}) && board[i][j] == sym))
            {
                (sym == 'X' ? player1_Score++ : player2_Score++);
                tuple<pair<int, int>, pair<int, int>, pair<int, int>> x({i, j}, {i, j + 1}, {i, j + 2});
                done.insert(x);
            }
        }
    }
    for (int i = 0; i <= 2; ++i)
    {
        for (int j = 0; j <= 4; j++)
        {
            // Check Vertical
            if ((all_equal(board[i][j], board[i + 1][j], board[i + 2][j]) && not_yet_counted({i, j}, {i + 1, j}, {i + 2, j}) && board[i][j] == sym))
            {
                (sym == 'X' ? player1_Score++ : player2_Score++);
                tuple<pair<int, int>, pair<int, int>, pair<int, int>> x({i, j}, {i + 1, j}, {i + 2, j});
                done.insert(x);
            }
        }
    }

    // Check diagonals
    for (int row = 0; row <= 2; ++row)
    {
        for (int col = 0; col <= 2; ++col)
        {
            // Main Diagonal direction
            if ((all_equal(board[row][col], board[row + 1][col + 1], board[row + 2][col + 2]) && board[row][col] == sym) && not_yet_counted({row, col}, {row + 1, col + 1}, {row + 2, col + 2}))
            {
                (sym == 'X' ? player1_Score++ : player2_Score++);
                tuple<pair<int, int>, pair<int, int>, pair<int, int>> x({row, col}, {row + 1, col + 1}, {row + 2, col + 2});
                done.insert(x);
            }
        }
    }
    for (int row = 0; row <= 2; ++row)
    {
        for (int col = 4; col >= 2; --col)
        {
            // Anti-Diagonal direction
            if ((all_equal(board[row][col], board[row + 1][col - 1], board[row + 2][col - 2]) && board[row][col] == sym) && not_yet_counted({row, col}, {row + 1, col - 1}, {row + 2, col - 2}))
            {
                (sym == 'X' ? player1_Score++ : player2_Score++);
                tuple<pair<int, int>, pair<int, int>, pair<int, int>> x({row, col}, {row + 1, col - 1}, {row + 2, col - 2});
                done.insert(x);
            }
        }
    }
}
bool FiveXFive_Board::update_board(Move<char> *move)
{
    int x = move->get_x();
    int y = move->get_y();
    char mark = move->get_symbol();

    // Validate move and apply if valid
    if (!(x < 0 || x >= rows || y < 0 || y >= columns) &&
        (board[x][y] == blank_symbol || mark == 0))
    {

        if (mark == 0)
        { // Undo move
            n_moves--;
            board[x][y] = blank_symbol;
        }
        else
        { // Apply move
            n_moves++;
            board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

bool FiveXFive_Board::is_lose(Player<char> *player)
{
    // Update scores before checking lose condition
    plus(player);
    // Game ends at 24 moves (one spot left usually or logic specific to this implemention)
    return (n_moves == 24 && player2_Score < player1_Score);
}

bool FiveXFive_Board::is_draw(Player<char> *player)
{
    return (n_moves == 24 && !is_lose(player));
}

bool FiveXFive_Board::game_is_over(Player<char> *player)
{
    return is_lose(player) || is_draw(player);
}