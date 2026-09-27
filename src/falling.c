#include <stdlib.h>
#include <time.h>

#include "header/global.h"

int fall_start_time = 0;
int move_start_time = 0;

void move_left() {
    // Add something that confirms that a move is possible
    if ((time(NULL) - move_start_time) > 1) {
        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;

        tetrimino_spots[0][0]--;
        tetrimino_spots[1][0]--;
        tetrimino_spots[2][0]--;
        tetrimino_spots[3][0]--;

        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 1;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 1;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 1;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 1;

        move_start_time = time(NULL);
    }
}
void move_right() {
    // Add something that confirms the move is possible
    if ((time(NULL) - move_start_time) > 1) {
        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;

        tetrimino_spots[0][0]++;
        tetrimino_spots[1][0]++;
        tetrimino_spots[2][0]++;
        tetrimino_spots[3][0]++;

        board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 1;
        board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 1;
        board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 1;
        board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 1;

        move_start_time = time(NULL);
    }
}
void rotate_block() {}

void spawn_block() {
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
}

void piece_falling() {
    if (currently_falling) {
        // Stop the piece from falling if it has hit the bottom
        // Determine if it's time for the piece to fall one block, if so, move it down
        if ((time(NULL) - fall_start_time) > 1) {
            // fall
            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 0;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 0;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 0;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 0;

            tetrimino_spots[0][1]++;
            tetrimino_spots[1][1]++;
            tetrimino_spots[2][1]++;
            tetrimino_spots[3][1]++;

            board[tetrimino_spots[0][0]][tetrimino_spots[0][1]] = 1;
            board[tetrimino_spots[1][0]][tetrimino_spots[1][1]] = 1;
            board[tetrimino_spots[2][0]][tetrimino_spots[2][1]] = 1;
            board[tetrimino_spots[3][0]][tetrimino_spots[3][1]] = 1;

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
