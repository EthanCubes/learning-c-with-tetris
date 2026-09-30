#include <stdbool.h>

#include "header/global.h"
#include "header/pieces.h"

void check_rows() {
    bool row_status[20] = {false}; // false by default because yeah

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
            // This means that the line is full
            row_status[y] = true;
        }
        else {
            row_status[y] = false;
        }
    }

    // Act on the 20 rows
    for (int i = 0; i < 20; i++) {
        if (!row_status[i]) {
            // If there isn't complete row, skip it and check the next one
            continue;
        }
        // Then, clear the line
        for (int a = 0; a < 10; a++) {
            board[a][i] = 0;
        }
    }
}

/*
// This code doesn't work, has been commented out because I need to rewrite the entire code
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
            score += 10;
            lines++;

            // something or another
            for (int row = y; row > 0; row--) {
                for (int column = 0; column < 10; column++) {
                    if (row != 1) {
                        if (!is_falling(column, row)) {
                            board[column][row] = board[column][row-1];
                        }
                    }
                    else {
                        board[column][row] = 0;
                    }
                }
            }
        }
    }
}
    */
