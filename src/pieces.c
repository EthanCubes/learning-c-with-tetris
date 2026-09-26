#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"

#include "header/global.h"
#include "header/clearing.h"
#include "header/user_input.h"
#include "header/falling.h"

bool currently_falling = false;

void piece_calc() {
    check_rows(); // Clear rows if they are filled (pretty much complete)
    falling_pieces(); // Generate falling pieces that can fall, rotate and will stop falling (incomplete)
    user_input(); // Accepts the user input and redirects it to rotate and move pieces (good enough)
}
