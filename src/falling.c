#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "header/global.h"
#include "header/pieces.h"

int fall_start_time = 0;
int move_start_time = 0;

void move_left() {
    // Add something that confirms that a move is possible
    for (int i = 0; i < 4; i++) { 
        if (tetrimino_spots[i][0] == 0) {
            return;
        }
    }
    if ((time(NULL) - move_start_time) > 1) {
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

        move_start_time = time(NULL);
    }
}
void move_right() {
    // Add something that confirms the move is possible
    for (int i = 0; i < 4; i++) { 
        if (tetrimino_spots[i][0] == 9) {
            return;
        }
    }
    if ((time(NULL) - move_start_time) > 1) {
        int color_int = board[tetrimino_spots[0][0]][tetrimino_spots[0][1]];
        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
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

        move_start_time = time(NULL);
    }
}
void rotate_block() {}

void spawn_block() {
    switch (rand()%6) {
        case 0:
            // currently, I'm only going to spawn the most simple block
            // Spawning the 2x2 block
            board[4][0] = 2;
            board[5][0] = 2;
            board[4][1] = 2;
            board[5][1] = 2;

            tetrimino_spots[0][0] = 4;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 5;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 4;
            tetrimino_spots[2][1] = 1;
            tetrimino_spots[3][0] = 5;
            tetrimino_spots[3][1] = 1;
            break;
        case 1:
            board[3][0] = 1;
            board[4][0] = 1;
            board[4][1] = 1;
            board[5][1] = 1;

            tetrimino_spots[0][0] = 3;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 4;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 4;
            tetrimino_spots[2][1] = 1;
            tetrimino_spots[3][0] = 5;
            tetrimino_spots[3][1] = 1;
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
            break;
        case 3:
            board[3][0] = 4;
            board[4][0] = 4;
            board[5][0] = 4;
            board[6][0] = 4;

            tetrimino_spots[0][0] = 3;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 4;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 5;
            tetrimino_spots[2][1] = 0;
            tetrimino_spots[3][0] = 6;
            tetrimino_spots[3][1] = 0;
            break;
        case 4:
            board[3][0] = 5;
            board[4][0] = 5;
            board[5][0] = 5;
            board[5][1] = 5;

            tetrimino_spots[0][0] = 3;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 4;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 5;
            tetrimino_spots[2][1] = 0;
            tetrimino_spots[3][0] = 5;
            tetrimino_spots[3][1] = 1;
            break;
        case 5:
            board[3][0] = 6;
            board[4][0] = 6;
            board[5][0] = 6;
            board[3][1] = 6;

            tetrimino_spots[0][0] = 3;
            tetrimino_spots[0][1] = 0;
            tetrimino_spots[1][0] = 4;
            tetrimino_spots[1][1] = 0;
            tetrimino_spots[2][0] = 5;
            tetrimino_spots[2][1] = 0;
            tetrimino_spots[3][0] = 3;
            tetrimino_spots[3][1] = 1;
            break;
    }
}

void piece_falling() {
    if (currently_falling) {
        // Stop the piece from falling if it has hit the bottom
        for (int i = 0; i < 4; i++) { 
            if (tetrimino_spots[i][1] == 19) {
                currently_falling = false;
                return;
            }
        }
        // Stop the piece from falling if it hits a piece
        for (int i = 0; i < 4; i++) {
            if (board[tetrimino_spots[i][0]][tetrimino_spots[i][1]+1] != 0 && !is_falling(tetrimino_spots[i][0], tetrimino_spots[i][1]+1)) {
                currently_falling = false;
                return;
            }
        }
        // Determine if it's time for the piece to fall one block, if so, move it down
        if ((time(NULL) - fall_start_time) > 1) {
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

            fall_start_time = time(NULL);
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
