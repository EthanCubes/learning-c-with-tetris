#include "raylib.h"

void user_input() {
    // Mian movement keys
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        // Move the falling piece left
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        // Move thef allign piece right
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        // Flip the piece
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
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
