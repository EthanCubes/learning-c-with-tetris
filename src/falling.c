#include <stdlib.h>
#include <time.h>

#include "header/global.h"

void move_left() {}
void move_right() {}
void rotate_block() {}

void piece_falling() {
    if (currently_falling) {
        // Stop the piece from falling if it has hit the bottom
        // Determine if it's time for the piece to fall one block, if so, move it down
    }
    else {
        // come up with a change, if the stats are good, throw a pice down
        if (rand()%100 == 0) {
            // spawn a block
            currently_falling = true;
            fall_start_time = time(NULL);
        }
    }
}
