#include "raylib.h"

#include "header/global.h"
#include "header/render.h"
#include "header/pieces.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    SetExitKey(KEY_NULL);
    SetTargetFPS(GetMonitorRefreshRate(0));
    while (!WindowShouldClose()) {
        // Simulation
        piece_calc(); // This also covered user input I think

        // Rendering
        BeginDrawing();
        ClearBackground(DARKGRAY);
        draw_board();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
