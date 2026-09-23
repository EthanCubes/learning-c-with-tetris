#include <stdio.h>
#include "raylib.h"

int main() {
    InitWindow(720, 720, "Tetris Clone");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
