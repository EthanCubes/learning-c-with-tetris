#include <stdlib.h>
#include <time.h>

#include "header/global.h"

int fall_start_time = 0;

void move_left() {}
void move_right() {}
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
