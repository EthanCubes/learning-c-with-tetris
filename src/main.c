#include "raylib.h"

#include "global.h"
#include "board.h"
#include "pieces.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    while (!WindowShouldClose()) {
        // Simulation
        piece_calc();

        // Rendering
        BeginDrawing();
        ClearBackground(DARKGRAY);
        draw_board();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
