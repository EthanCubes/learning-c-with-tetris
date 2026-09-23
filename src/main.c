#include <stdio.h>
#include "raylib.h"

void draw_board() {
    // the board is a 10x20 grid
    int tile_width = 24;
    int tile_height = 24;
    int x_offset = (720 - 10*tile_width)/2;
    int y_offset = (720 - 20*tile_height)/2;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            DrawRectangle(x*tile_width+x_offset, y*tile_height+y_offset, tile_width, tile_height, BLACK);
        }
    }
}

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
