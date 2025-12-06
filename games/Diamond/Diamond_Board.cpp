#include "Diamond_Board.h"
#include <vector>

Diamond_Board::Diamond_Board() :Board(5, 5)
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

    if (row < 0 || row >= 5 || col < 0 || col >= 5) return false;

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

    // Horizontale 3 marks
    for (int r = 1; r < 4; r += 2) {
        vector<pair<int, int>> L3;
        for (int c = 1; c < 4; c++) {
            if (board[r][c] == s) {
                L3.push_back({ r,c });
            }
        }
        if (L3.size() == 3) lines_3.push_back(L3);
    }

    // Horizontale 4 marks
    vector<pair<int, int>> L4;
    for (int c = 0; c <= 4; ++c) {
        if (board[2][c] == s) L4.push_back({ 2,c });
    }
    if (L4.size() == 4) lines_4.push_back(L4);

    // les diagonales
    vector<vector<pair<int, int>>> diagonals = {
        { {0,2}, {1,1}, {2,0} },
        { {0,2}, {1,3}, {2,4} },
        { {1,1}, {2,2}, {3,3} },
        { {1,3}, {2,2}, {3,1} },
        { {2,0}, {3,1}, {4,2} },
        { {2,4}, {3,3}, {4,2} }
    };

    for (auto& diag : diagonals) {
        if (board[diag[0].first][diag[0].second] == s &&
            board[diag[1].first][diag[1].second] == s &&
            board[diag[2].first][diag[2].second] == s) {
            lines_3.push_back(diag);
        }
    }

    // Verticale 3 marks
    if (board[1][1] == s && board[2][1] == s && board[3][1] == s)
        lines_3.push_back({ {1,1},{2,1},{3,1} });
    if (board[1][3] == s && board[2][3] == s && board[3][3] == s)
        lines_3.push_back({ {1,3},{2,3},{3,3} });

    // Verticale 4 marks
    vector<pair<int, int>> L4v = { {0,2},{1,2},{2,2},{3,2} };
    if (board[0][2] == s && board[1][2] == s && board[2][2] == s && board[3][2] == s)
        lines_4.push_back(L4v);
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
   return Moves == 13 && !is_win(player);
}

bool Diamond_Board::game_is_over(Player<char>* player)
{
    return  is_win(player) || is_lose(player) || is_draw(player);
}
