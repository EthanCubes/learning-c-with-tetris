#include <stdio.h>
#include "raylib.h"

int main() {
    InitWindow(540, 720, "Tetris Clone");
    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
