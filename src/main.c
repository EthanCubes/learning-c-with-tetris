#include "raylib.h"

#include "global.h"
#include "render.h"
#include "pieces.h"

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
