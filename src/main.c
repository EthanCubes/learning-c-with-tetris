#include "raylib.h"

#include "board.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        draw_board();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
