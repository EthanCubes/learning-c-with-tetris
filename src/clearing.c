#include <stdbool.h>

#include "header/global.h"

bool is_falling(int x, int y) {
    for (int block = 0; block < 4; block++) {
        if (tetrimino_spots[block][0] == x && tetrimino_spots[block][1] == y) {
            return true;
        }
    }
    return false;
}

void check_rows() {
    for (int y = 0; y < 20; y++) {
        int filled_squares = 0;
        for (int x = 0; x < 10; x ++) {
            if (board[x][y] != 0 && !is_falling(x, y)) {
                filled_squares++;
            }
        }
        if (filled_squares == 10) {
            // This means that a row is full, so I need to clear this
            for (int row = y; row > 0; row--) {
                for (int column = 0; column < 10; column++) {
                    if (row != 1) {
                        board[column][row] = board[column][row-1];
                    }
                    else {
                        board[column][row] = 0;
                    }
                }
            }
        }
    }
}
