#include "raylib.h"

#include "global.h"
#include "board.h"
#include "pieces.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    SetExitKey(KEY_NULL);
    SetTargetFPS(GetMonitorRefreshRate(0));
    while (!WindowShouldClose()) {
        // Simulation
        BeginDrawing(); // premature to make sure that the thing works
        piece_calc(); // This also covered user input I think

        // Rendering
        BeginDrawing();
        DrawFPS(0, 20);
        ClearBackground(DARKGRAY);
        draw_board();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
