# ifndef PYRAMID_BOARD_H
# define PYRAMID_BOARD_H
# include "BoardGame_Classes.h"
using namespace std;

class Pyramid_Board : public Board<char> {
private:
    char blank_symbol = '.';
    char invalid_symbol = ' '; // will print as empty space

    // All winning lines: each is 3 coordinates (x,y)
    vector<vector<pair<int,int>>> winning_lines;

    // Initialize all winning lines for Pyramid X-O
    void init_winning_lines();

public:
    Pyramid_Board();

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override {return false;};
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;

    bool is_valid_cell(int r, int c) const;
    char get_blank_symbol() const { return blank_symbol; }
    char get_cell(int r, int c) const { return board[r][c]; }
};

#endif // PYRAMID_BOARD_H