#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "raylib.h"

#include "header/global.h"
#include "header/render.h"
#include "header/pieces.h"

int score = 0;
int lines = 0;

bool gameover = false;

int fall_time;

int level = 1;

int fall_speed_per_level[30] = {
    500,
    400,
    300,
    250,
    225,
    200,
    175,
    160,
    150,
    140,
    135,
    130,
    125,
    120,
    115,
    110,
    105,
    100,
    95,
    90,
    85,
    80,
    75,
    70,
    65,
    60,
    50, 
    40, 
    25,
    0
};

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
            level = 1 + floor(lines / 10);
            if (level <= 30) {
                fall_time = fall_speed_per_level[level - 1];
            }
            else {
                fall_time = 0;
            }
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
            DrawText("Game over! Press Q to quit and N to start new game", 0, 90, 20, WHITE);
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
