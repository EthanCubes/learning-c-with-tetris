#include <stdbool.h>

#include "global.h"

// This file is for piece movement, including handling user inputs

bool is_falling(int x, int y) {
    for (int block = 0; block < 4; block++) {
        if (tetrimino_spots[block][0] == x && tetrimino_spots[block][1] == y) {
            return true;
        }
    }
    return false;
}

void check_rows() {
    for (int row = 0; row < 20; row++) {
        int filled_squares = 0;
        for (int column = 0; column < 10; column++) {
            if (board[row][column] != 0 && !is_falling(row, column)) {
                filled_squares++;
            }
        }
        if (filled_squares == 10) {
            // this needs to like move all the top squares down, idk how
        }
    }
}

void piece_calc() {}