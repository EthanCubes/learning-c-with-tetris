#include "raylib.h"

#include "global.h"
#include "board.h"
#include "pieces.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    SetExitKey(KEY_NULL);
    while (!WindowShouldClose()) {
        // Simulation
        BeginDrawing(); // premature to make sure that the thing works
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
