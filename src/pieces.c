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
    check_rows(); // Clear rows if they are filled (pretty much complete)
    falling_pieces(); // Generate falling pieces that can fall, rotate and will stop falling (incomplete)
    user_input(); // Accepts the user input and redirects it to rotate and move pieces (incomplete)
}
