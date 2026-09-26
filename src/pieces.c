#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"

#include "header/global.h"
#include "header/clearing.h"
#include "header/user_input.h"

bool currently_falling = false;

void falling_pieces() {
    if (currently_falling) {
        // simulate the falling thing
    }
    else {
        srand(time(NULL));
        int r = rand()%10;
        if (r = 0) {
            // summon a falling piece
        }
    }
}

void piece_calc() {
    check_rows();
    falling_pieces();
    user_input();
}
