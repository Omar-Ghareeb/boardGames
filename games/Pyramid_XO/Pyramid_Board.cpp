# include "Pyramid_Board.h"
using namespace std;

Pyramid_Board::Pyramid_Board() : Board<char>(3, 5) {
    // Initialize the board with invalid symbols
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            board[r][c] = invalid_symbol;
        }
    }

    // Set valid pyramid cells to blank symbol
    board[0][2] = blank_symbol;
    board[1][1] = blank_symbol; board[1][2] = blank_symbol; board[1][3] = blank_symbol;
    for (int c = 0; c < 5; ++c) {
        board[2][c] = blank_symbol;
    }

    init_winning_lines();
}

void Pyramid_Board::init_winning_lines() {
    // Diagonal lines
    winning_lines.push_back({{0,2}, {1,1}, {2,0}});
    winning_lines.push_back({{0,2}, {1,3}, {2,4}});

    // Vertical lines
    winning_lines.push_back({{0,2}, {1,2}, {2,2}});
     
    // Horizontal lines
    winning_lines.push_back({{1,1}, {1,2}, {1,3}});
    winning_lines.push_back({{2,0}, {2,1}, {2,2}});
    winning_lines.push_back({{2,1}, {2,2}, {2,3}});
    winning_lines.push_back({{2,2}, {2,3}, {2,4}});
}

bool Pyramid_Board::is_valid_cell(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= columns)
        return false;

    if (r == 0 && c == 2)
        return true;
    else if (r == 1 && (c == 1 || c == 2 || c == 3))
        return true;
    else if (r == 2 && (c >= 0 && c <= 4))
        return true;
    else return false;
}

bool Pyramid_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    if (!is_valid_cell(x, y))
        return false;

    if (board[x][y] != blank_symbol)
        return false;

    board[x][y] = symbol;
    n_moves++;
    return true;
}

bool Pyramid_Board::is_win(Player<char>* player){
    char symbol = player->get_symbol();

    for (const auto& line : winning_lines) {
        for (const auto& coord : line) {
        char a = board[line[0].first][line[0].second];
        char b = board[line[1].first][line[1].second];
        char c = board[line[2].first][line[2].second];
        if (a != blank_symbol && a == b && b == c && a == symbol)
            return true;
        }
    }
    return false;
}

bool Pyramid_Board::is_draw(Player<char>* player) {
    return n_moves >= 9 && !is_win(player);
}

bool Pyramid_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}