#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"

#include "header/global.h"
#include "header/clearing.h"
#include "header/user_input.h"
#include "header/falling.h"

bool currently_falling = false;

int tetrimino_spots[4][2] = {0};

bool is_falling(int x, int y) {
    for (int block = 0; block < 4; block++) {
        if (tetrimino_spots[block][0] == x && tetrimino_spots[block][1] == y) {
            return true;
        }
    }
    return false;
}

void piece_calc() {
    check_rows(); // Clear rows if they are filled (pretty much complete)
    piece_falling(); // Generate falling pieces that can fall, rotate and will stop falling (incomplete)
    user_input(); // Accepts the user input and redirects it to rotate and move pieces (good enough)
}
