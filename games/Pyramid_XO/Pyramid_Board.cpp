#include "Pyramid_Board.h"
using namespace std;

Pyramid_Board::Pyramid_Board() : Board<char>(3, 5)
{
    // Initialize the entire 3x5 matrix with invalid symbols (spaces)
    // This effectively "hides" the non-playable parts of the rectangle
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            board[r][c] = invalid_symbol;
        }
    }

    // Explicitly set the valid pyramid cells to the blank symbol (.)
    // Row 0: Tip of the pyramid (0, 2)
    board[0][2] = blank_symbol;

    // Row 1: Middle section (1, 1), (1, 2), (1, 3)
    board[1][1] = blank_symbol;
    board[1][2] = blank_symbol;
    board[1][3] = blank_symbol;

    // Row 2: Base of the pyramid (2, 0) to (2, 4)
    for (int c = 0; c < 5; ++c)
    {
        board[2][c] = blank_symbol;
    }

    init_winning_lines();
}

void Pyramid_Board::init_winning_lines()
{
    // Define all winning 3-in-a-row combinations

    // Diagonal lines
    winning_lines.push_back({{0, 2}, {1, 1}, {2, 0}}); // Left diagonal
    winning_lines.push_back({{0, 2}, {1, 3}, {2, 4}}); // Right diagonal

    // Vertical line (Center column)
    winning_lines.push_back({{0, 2}, {1, 2}, {2, 2}});

    // Horizontal lines
    winning_lines.push_back({{1, 1}, {1, 2}, {1, 3}}); // Middle row
    winning_lines.push_back({{2, 0}, {2, 1}, {2, 2}}); // Bottom row left
    winning_lines.push_back({{2, 1}, {2, 2}, {2, 3}}); // Bottom row center
    winning_lines.push_back({{2, 2}, {2, 3}, {2, 4}}); // Bottom row right
}

bool Pyramid_Board::is_valid_cell(int r, int c) const
{
    if (r < 0 || r >= rows || c < 0 || c >= columns)
        return false;

    // Specific logic to define the pyramid shape
    if (r == 0 && c == 2)
        return true;
    else if (r == 1 && (c == 1 || c == 2 || c == 3))
        return true;
    else if (r == 2 && (c >= 0 && c <= 4))
        return true;
    else
        return false;
}

bool Pyramid_Board::update_board(Move<char> *move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    // Check bounds and shape validity
    if (!is_valid_cell(x, y))
        return false;

    // Check availability
    if (board[x][y] != blank_symbol)
        return false;

    board[x][y] = symbol;
    n_moves++;
    return true;
}

bool Pyramid_Board::is_win(Player<char> *player)
{
    char symbol = player->get_symbol();

    // Iterate over pre-calculated lines to check for a win
    for (const auto &line : winning_lines)
    {
        // Since we iterate via line, we just need to check if the cells match
        // Note: The inner loop logic here is slightly redundant (checking all 3 in every iteration)
        // but functionally correct given the structure.
        char a = board[line[0].first][line[0].second];
        char b = board[line[1].first][line[1].second];
        char c = board[line[2].first][line[2].second];

        if (a != blank_symbol && a == b && b == c && a == symbol)
            return true;
    }
    return false;
}

bool Pyramid_Board::is_draw(Player<char> *player)
{
    // 9 total valid cells in the pyramid
    return n_moves >= 9 && !is_win(player);
}

bool Pyramid_Board::game_is_over(Player<char> *player)
{
    return is_win(player) || is_draw(player);
}