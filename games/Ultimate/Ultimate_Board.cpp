#include "Ultimate_Board.h"
using namespace std;

Ultimate_Board::Ultimate_Board() : Board(9, 9)
{
    // Initialize all cells with blank_symbol
    for (auto &row : board)
        for (auto &cell : row)
            cell = blank_symbol;

    // Initialize meta-board to 'c' (contested/continue)
    memset(boards, 'c', sizeof(boards));
}

void Ultimate_Board::MiniGridDOne(char sym)
{
    // Lambda to check 3 chars for equality
    auto all_equal = [&](char a, char b, char c)
    {
        return a == b && b == c && a != blank_symbol;
    };

    // --- Check Vertical and Horizontal wins within sub-grids ---
    // i iterates through the starting ROW indices of the sub-grids (0, 3, 6)
    for (int i = 0; i < 9; i += 3)
    {
        // j iterates through ALL columns (0 to 8)
        for (int j = 0; j < 9; j++)
        {
            // Check Vertical Line in a sub-grid
            if (all_equal(board[i][j], board[i + 1][j], board[i + 2][j]))
            {
                // If this sub-grid is not yet won ('c')
                if (boards[i / 3][j / 3] == 'c')
                {
                    // Mark sub-grid as won by sym
                    boards[i / 3][j / 3] = sym;

                    // Fill the entire 3x3 sub-grid with the winner's symbol
                    for (int x = i; x < i + 3; x++)
                    {
                        // Logic to handle decrementing n_moves correctly as we overwrite cells
                        // (Complex loop logic handles updating the visual board)
                        if (j == 0 || j == 3 || j == 6)
                        {
                            for (int Y = j; Y < j + 3; Y++)
                            {
                                board[x][Y] = toupper(sym);
                                n_moves--;
                            }
                            n_moves++;
                        }
                        else if (j == 1 || j == 4 || j == 7)
                        {
                            board[x][j - 1] = toupper(sym);
                            board[x][j] = toupper(sym);
                            board[x][j + 1] = toupper(sym);
                            n_moves -= 2;
                        }
                        else
                        {
                            for (int y = j - 2; y <= j; y++)
                            {
                                board[x][y] = toupper(sym);
                                n_moves--;
                            }
                            n_moves++;
                        }
                    }
                }
            }
            // Check Horizontal Line in a sub-grid
            else if (all_equal(board[j][i], board[j][i + 1], board[j][i + 2]))
            {
                if (boards[j / 3][i / 3] == 'c')
                {
                    boards[j / 3][i / 3] = sym;
                    // Fill sub-grid visual logic...
                    for (int x = i; x < i + 3; x++)
                    {
                        if (j == 0 || j == 3 || j == 6)
                        {
                            for (int Y = j; Y < j + 3; Y++)
                            {
                                board[Y][x] = toupper(sym);
                                n_moves--;
                            }
                            n_moves++;
                        }
                        else if (j == 1 || j == 4 || j == 7)
                        {
                            board[j - 1][x] = toupper(sym);
                            board[j][x] = toupper(sym);
                            board[j + 1][x] = toupper(sym);
                            n_moves -= 2;
                        }
                        else
                        {
                            for (int y = j - 2; y <= j; y++)
                            {
                                board[y][x] = toupper(sym);
                                n_moves--;
                            }
                            n_moves++;
                        }
                    }
                }
            }
        }
    }

    // --- Check Diagonals within sub-grids ---
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            if (all_equal(board[i][j], board[i + 1][j + 1], board[i + 2][j + 2]) ||
                all_equal(board[i][j + 2], board[i + 1][j + 1], board[i + 2][j]))
            {
                if (boards[i / 3][j / 3] == 'c')
                {
                    boards[i / 3][j / 3] = sym;
                    // Fill sub-grid
                    for (int X = i; X < i + 3; X++)
                    {
                        for (int Y = j; Y < j + 3; Y++)
                        {
                            board[X][Y] = toupper(sym);
                            n_moves--;
                        }
                        n_moves++;
                    }
                }
            }
        }
    }
}

bool Ultimate_Board::update_board(Move<char> *move)
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
            // n_moves--; // Commented out in original
            board[x][y] = blank_symbol;
        }
        else
        {              // Apply move
            n_moves--; // Decrement available moves
            board[x][y] = toupper(mark);
        }

        // Check if this move won a small grid
        MiniGridDOne(mark);

        return true;
    }
    return false;
}

bool Ultimate_Board::is_win(Player<char> *player)
{
    const char sym = player->get_symbol();

    auto all_equal = [&](char a, char b, char c)
    {
        return a == b && b == c && a != blank_symbol;
    };

    // Check rows and columns of the META-BOARD (the 3x3 grid of sub-grid results)
    for (int i = 0; i < 3; ++i)
    {
        if ((all_equal(boards[i][0], boards[i][1], boards[i][2]) && boards[i][0] == sym) ||
            (all_equal(boards[0][i], boards[1][i], boards[2][i]) && boards[0][i] == sym))
            return true;
    }

    // Check diagonals of the META-BOARD
    if ((all_equal(boards[0][0], boards[1][1], boards[2][2]) && boards[1][1] == sym) ||
        (all_equal(boards[0][2], boards[1][1], boards[2][0]) && boards[1][1] == sym))
        return true;

    return false;
}

bool Ultimate_Board::is_draw(Player<char> *player)
{
    return (n_moves == 0 && !is_win(player));
}

bool Ultimate_Board::game_is_over(Player<char> *player)
{
    return is_win(player) || is_draw(player);
}