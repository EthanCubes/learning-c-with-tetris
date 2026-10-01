#include <stdlib.h>
#include <time.h>

#include "raylib.h"

#include "header/global.h"
#include "header/render.h"
#include "header/pieces.h"

int score = 0;
int lines = 0;

bool gameover = false;

void reset() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            board[x][y] = 0;
        }
    }
    for (int x = 0; x < 4; x++) {
        for (int y = 2; y < 2; y++) {
            tetrimino_spots[x][y] = 0;
        }
    }
    currently_falling = false;
    score = 0;
    lines = 0;
    gameover = false;
}

int main() {
    srand(time(NULL));

    InitWindow(720, 720, "Tetris Clone");
    SetExitKey(KEY_Q);
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        while (!gameover && !WindowShouldClose()) {
            // Simulation
            piece_calc(); // This also covered user input I think

            if (IsKeyDown(KEY_N)) {
                reset();
            }

            // Rendering
            BeginDrawing();
            ClearBackground(DARKGRAY);
            draw_board();
            EndDrawing();
        }
        if (gameover) {
            BeginDrawing();
            DrawText("Game over! Press Q to quit and N to start new game", 0, 60, 20, WHITE);
            if (IsKeyDown(KEY_N)) {
                reset();
            }
            draw_board();
            ClearBackground(DARKGRAY);
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}
