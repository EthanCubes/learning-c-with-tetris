#include <stdbool.h>

#include "header/global.h"
#include "header/pieces.h"

void check_rows() {
    // Scan all 20 rows
    for (int y = 0; y < 20; y++) {
        // Scan a row
        int filled_squares = 0;
        for (int x = 0; x < 10; x++) {
            if (board[x][y] != 0 && !is_falling(x, y)) {
                filled_squares++;
            }
        }
        if (filled_squares == 10) {
            // Add score
            score += 10;
            // Clear line
            for (int x = 0; x < 10; x++) {
                if (!is_falling(x, y)) {
                    board[x][y] = 0;
                }
            }
            // Shift everything down
            for (int row = y; row > 0; row--) {
                for (int column = 0; column < 10; column++) {
                    if (!is_falling(column, row) && !is_falling(column, row - 1)) {
                        board[column][row] = board[column][row - 1];
                    }
                }
            }
            for (int column = 0; column < 10; column++) {
                if (!is_falling(column, 0)) {
                    board[column][0] = 0;
                }
            }
        }
    }
}
