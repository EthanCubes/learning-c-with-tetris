#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "header/global.h"
#include "header/pieces.h"
#include "header/time.h"

int fall_start_time = 0;

int left_cooldown = 0;
int right_cooldown = 0;
int rotate_cooldown = 0;

void move_left() {
    // Add something that confirms that a move is possible
    for (int i = 0; i < 4; i++) { 
        if (tetrimino_spots[i][0] == 0) {
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (board[tetrimino_spots[i][0]-1][tetrimino_spots[i][1]] != 0 && !is_falling(tetrimino_spots[i][0]-1, tetrimino_spots[i][1])) {
            return;
        }
    }
    if ((time_in_milliseconds() - left_cooldown) > 125) {
        int color_int = board[tetrimino_spots[0][0]][tetrimino_spots[0][1]];
        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;

        tetrimino_spots[0][0]--;
        tetrimino_spots[1][0]--;
        tetrimino_spots[2][0]--;
        tetrimino_spots[3][0]--;

        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = color_int;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = color_int;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = color_int;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = color_int;

        left_cooldown = time_in_milliseconds();
    }
}

void move_right() {
    // Add something that confirms the move is possible
    for (int i = 0; i < 4; i++) { 
        if (tetrimino_spots[i][0] == 9) {
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (board[tetrimino_spots[i][0]+1][tetrimino_spots[i][1]] != 0 && !is_falling(tetrimino_spots[i][0]+1, tetrimino_spots[i][1])) {
            return;
        }
    }
    if ((time_in_milliseconds() - right_cooldown) > 125) {
        int color_int = board[tetrimino_spots[0][0]][tetrimino_spots[0][1]]; board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;

        tetrimino_spots[0][0]++;
        tetrimino_spots[1][0]++;
        tetrimino_spots[2][0]++;
        tetrimino_spots[3][0]++;

        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = color_int;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = color_int;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = color_int;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = color_int;

        right_cooldown = time_in_milliseconds();
    }
}

bool check_valid_rotation() {
    int pivot_x = tetrimino_spots[0][0];
    int pivot_y = tetrimino_spots[0][1];
    for (int i = 1; i < 4; i++) {
        int old_x = tetrimino_spots[i][0];
        int old_y = tetrimino_spots[i][1];

        int new_x = pivot_x - (old_y - pivot_y);
        int new_y = pivot_y + (old_x - pivot_x);

        if (new_x < 0 || new_x > 9) {
            return false;
        }
        else if (new_y < 0 || new_y > 19) {
            return false;
        }
        else if (board[new_x][new_y] != 0 && !is_falling(new_x, new_y)) {
            return false;
        }
    }
    return true;
}

void rotate_block() {
    // highkey hardest part
    // Need to ensure that rotation does not cause integer overflow
    if ((time_in_milliseconds() - rotate_cooldown) < 125) {
        // different from the others
        return;
    }
    int pivot_x = tetrimino_spots[0][0];
    int pivot_y = tetrimino_spots[0][1];
    switch (falling_shape) {
        case 0:
            // Square
            // Nothing needs to be done
            break;
        case 1:
            // S-left
            if (!check_valid_rotation()) {
                return;
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;
            for (int i = 1; i < 4; i++) {
                // something
                int old_x = tetrimino_spots[i][0];
                int old_y = tetrimino_spots[i][1];

                tetrimino_spots[i][0] = pivot_x - (old_y - pivot_y);
                tetrimino_spots[i][1] = pivot_y + (old_x - pivot_x);
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = falling_shape + 1;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = falling_shape + 1;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = falling_shape + 1;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = falling_shape + 1;
            break;
        case 2:
            // S-right
            if (!check_valid_rotation()) {
                return;
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;
            for (int i = 1; i < 4; i++) {
                // something
                int old_x = tetrimino_spots[i][0];
                int old_y = tetrimino_spots[i][1];

                tetrimino_spots[i][0] = pivot_x - (old_y - pivot_y);
                tetrimino_spots[i][1] = pivot_y + (old_x - pivot_x);
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = falling_shape + 1;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = falling_shape + 1;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = falling_shape + 1;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = falling_shape + 1;
            break;
        case 3:
            // Line
            if (!check_valid_rotation()) {
                return;
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;
            for (int i = 1; i < 4; i++) {
                // something
                int old_x = tetrimino_spots[i][0];
                int old_y = tetrimino_spots[i][1];

                tetrimino_spots[i][0] = pivot_x - (old_y - pivot_y);
                tetrimino_spots[i][1] = pivot_y + (old_x - pivot_x);
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = falling_shape + 1;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = falling_shape + 1;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = falling_shape + 1;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = falling_shape + 1;
            break;
        case 4:
            // L-right
            if (!check_valid_rotation()) {
                return;
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;
            for (int i = 1; i < 4; i++) {
                // something
                int old_x = tetrimino_spots[i][0];
                int old_y = tetrimino_spots[i][1];

                tetrimino_spots[i][0] = pivot_x - (old_y - pivot_y);
                tetrimino_spots[i][1] = pivot_y + (old_x - pivot_x);
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = falling_shape + 1;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = falling_shape + 1;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = falling_shape + 1;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = falling_shape + 1;
            break;
        case 5:
            // L-left
            if (!check_valid_rotation()) {
                return;
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;
            for (int i = 1; i < 4; i++) {
                // something
                int old_x = tetrimino_spots[i][0];
                int old_y = tetrimino_spots[i][1];

                tetrimino_spots[i][0] = pivot_x - (old_y - pivot_y);
                tetrimino_spots[i][1] = pivot_y + (old_x - pivot_x);
            }
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = falling_shape + 1;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = falling_shape + 1;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = falling_shape + 1;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = falling_shape + 1;
            break;
    }
    rotate_cooldown = time_in_milliseconds();
}

void spawn_block() {
    switch (rand()%6) {
        case 0:
            // currently, I'm only going to spawn the most simple block
            // Spawning the 2x2 block
            board[4][0] = 1;
            board[5][0] = 1;
            board[4][1] = 1;
            board[5][1] = 1;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 5;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 4;
            tetrimino_spots[2][1] = 1;
            tetrimino_spots[3][0] = 5;
            tetrimino_spots[3][1] = 1;

            falling_shape = 0;

            break;
        case 1:
            board[3][0] = 2;
            board[4][0] = 2;
            board[4][1] = 2;
            board[5][1] = 2;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 3;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 4;
            tetrimino_spots[2][1] = 1;
            tetrimino_spots[3][0] = 5;
            tetrimino_spots[3][1] = 1;

            falling_shape = 1;

            break;
        case 2:
            board[4][0] = 3;
            board[5][0] = 3;
            board[3][1] = 3;
            board[4][1] = 3;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 5;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 3;
            tetrimino_spots[2][1] = 1;
            tetrimino_spots[3][0] = 4;
            tetrimino_spots[3][1] = 1;

            falling_shape = 2;

            break;
        case 3:
            board[3][0] = 4;
            board[4][0] = 4;
            board[5][0] = 4;
            board[6][0] = 4;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 3;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 5;
            tetrimino_spots[2][1] = 0;
            tetrimino_spots[3][0] = 6;
            tetrimino_spots[3][1] = 0;

            falling_shape = 3;

            break;
        case 4:
            board[3][0] = 5;
            board[4][0] = 5;
            board[5][0] = 5;
            board[5][1] = 5;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 3;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 5;
            tetrimino_spots[2][1] = 0;
            tetrimino_spots[3][0] = 5;
            tetrimino_spots[3][1] = 1;

            falling_shape = 4;

            break;
        case 5:
            board[3][0] = 6;
            board[4][0] = 6;
            board[5][0] = 6;
            board[3][1] = 6;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 3;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 5;
            tetrimino_spots[2][1] = 0;
            tetrimino_spots[3][0] = 3;
            tetrimino_spots[3][1] = 1;

            falling_shape = 5;

            break;
    }
}

void piece_falling() {
    if (currently_falling) {
        // Stop the piece from falling if it has hit the bottom
        for (int i = 0; i < 4; i++) { 
            if (tetrimino_spots[i][1] == 19) {
                currently_falling = false;
                score++;
                return;
            }
        }
        // Stop the piece from falling if it hits a piece
        for (int i = 0; i < 4; i++) {
            if (board[tetrimino_spots[i][0]][tetrimino_spots[i][1]+1] != 0 && !is_falling(tetrimino_spots[i][0], tetrimino_spots[i][1]+1)) {
                // Check if any of the pieces are at the top of the board. If so, end the game
                for (int a = 0; a < 4; a++) {
                    // Check if the y is 0, or the top of the board
                    if (tetrimino_spots[a][1] == 0) {
                        gameover = true;
                    }
            }
                currently_falling = false;
                score++;
                return;
            }
        }
        // Determine if it's time for the piece to fall one block, if so, move it down
        if ((time_in_milliseconds() - fall_start_time) > fall_time) {
            // fall
            int color_int = board[tetrimino_spots[0][0]][tetrimino_spots[0][1]];
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;

            tetrimino_spots[0][1]++;
            tetrimino_spots[1][1]++;
            tetrimino_spots[2][1]++;
            tetrimino_spots[3][1]++;

            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = color_int;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = color_int;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = color_int;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = color_int;

            fall_start_time = time_in_milliseconds();
        }
    }
    else {
        // come up with a change, if the stats are good, throw a pice down
        if (rand()%100 == 0) {
            // spawn a block
            spawn_block();
            currently_falling = true;
            fall_start_time = time(NULL);
        }
    }
}
