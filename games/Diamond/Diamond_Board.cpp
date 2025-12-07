#include "Diamond_Board.h"
#include <vector>

Diamond_Board::Diamond_Board() :Board(7, 7)
{
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (is_valid_cell(r, c))
                board[r][c] = blank_symbol;
            else
                board[r][c] = invalid_symbol;
        }
    }
}

bool Diamond_Board::is_valid_cell(int x, int y)
{
    for (auto& p : invalid)
    {
        if (p.first == x && p.second == y)
        {
            return false;
        }
    }

    return true;
}
bool Diamond_Board::update_board(Move<char>* move)
{
    int row = move->get_x();
    int col = move->get_y();

    if (row < 0 || row >= 7 || col < 0 || col >= 7) return false;

    if (board[row][col] != blank_symbol) return false;

    if (!is_valid_cell(row, col))
    {
        cout << "INVALID MOVE!";
        return false;
    }

    board[row][col] = move->get_symbol();

    Moves++;

    return true;

}
void Diamond_Board::check_direction(Player<char>* player, vector<vector<pair<int, int>>>& lines_3,
    vector<vector<pair<int, int>>>& lines_4)
{
    char s = player->get_symbol();

    const int DIRS[4][2] = {
        {0, 1},  // horizontale.
        {1, 0},  // verticale.
        {1, 1},  // diagonale en bas vers le droit.
        {1, -1}  // diagonale en bas vers le gauche.
    };

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            if (!is_valid_cell(r, c)) continue;
            if (board[r][c] != s) continue;

            for (auto& d : DIRS)
            {
                int dr = d[0], dc = d[1];

                vector<pair<int, int>> line3;
                for (int k = 0; k < 3; k++)
                {
                    int nr = r + dr * k;
                    int nc = c + dc * k;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= columns) goto skip3;
                    if (!is_valid_cell(nr, nc)) goto skip3;
                    if (board[nr][nc] != s) goto skip3;

                    line3.push_back({ nr,nc });
                }
                lines_3.push_back(line3);
            skip3:;

                vector<pair<int, int>> line4;
                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr * k;
                    int nc = c + dc * k;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= columns) goto skip4;
                    if (!is_valid_cell(nr, nc)) goto skip4;
                    if (board[nr][nc] != s) goto skip4;

                    line4.push_back({ nr,nc });
                }
                lines_4.push_back(line4);
            skip4:;
            }
        }
    }
}

bool Diamond_Board::share_one_cell(const vector<pair<int, int>>& ligne3, const vector<pair<int, int>>& ligne4)
{
    int x = 0; for (auto& a : ligne3)
    {
        for (auto& b : ligne4)
        {
            if (a == b) x++;
        }
    }
    if (x == 1) return true;
    else return false;
}
bool Diamond_Board::same_direction(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b)
{
    int ax = a[1].first - a[0].first;
    int ay = a[1].second - a[0].second;

    int bx = b[1].first - b[0].first;
    int by = b[1].second - b[0].second;

    return (ax == bx && ay == by);
}
bool Diamond_Board::is_win(Player<char>* player)
{
    vector<vector<pair<int, int>>> lines_3;
    vector<vector<pair<int, int>>> lines_4;

    check_direction(player, lines_3, lines_4);

    for (auto& L3 : lines_3) {
        for (auto& L4 : lines_4) {
            if (!same_direction(L3, L4) && share_one_cell(L3, L4))
                return true;  
        }
    }

    return false;
}

bool Diamond_Board::is_lose(Player<char>* player)
{
    return false;
}

bool Diamond_Board::is_draw(Player<char>* player)
{
   return Moves == 25 && !is_win(player);
}

bool Diamond_Board::game_is_over(Player<char>* player)
{
    return  is_win(player) || is_lose(player) || is_draw(player);
}
