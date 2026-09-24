#include "raylib.h"

#include "global.h"
#include "board.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    while (!WindowShouldClose()) {
        // Simulation

        // Rendering
        BeginDrawing();
        ClearBackground(DARKGRAY);
        draw_board();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
