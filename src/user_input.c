#include "raylib.h"

#include "header/global.h"
#include "header/falling.h"

void user_input() {
    // Mian movement keys
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        move_left();
        // Move the falling piece left
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        move_right();
        // Move thef allign piece right
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        rotate_block();
        // Flip the piece
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        fall_start_time = 0;
        // Accelerate
    }

    // Other miscellanious keys
    if (IsKeyDown(KEY_ESCAPE) || IsKeyDown(KEY_P)) {
        // Pause the game
    }
    if (IsKeyDown(KEY_N)) {
        // Restart the game
    }
}