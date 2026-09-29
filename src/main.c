#include <stdlib.h>
#include <time.h>

#include "raylib.h"

#include "header/global.h"
#include "header/render.h"
#include "header/pieces.h"

int score = 0;

int main() {
    srand(time(NULL));

    InitWindow(720, 720, "Tetris Clone");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Simulation
        piece_calc(); // This also covered user input I think

        // Rendering (this is already complete, yay!)
        BeginDrawing();
        ClearBackground(DARKGRAY);
        draw_board();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
