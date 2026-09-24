#include "raylib.h"

#include "global.h"

int board[10][20];

const Color COLOR_ARRAY[7] = {
    BLACK,
    BLUE,
    YELLOW,
    PINK,
    ORANGE,
    GREEN,
};

void draw_board() {
    // the board is a 10x20 grid
    int tile_width = 24;
    int tile_height = 24;
    int x_offset = (720 - 10*tile_width)/2;
    int y_offset = (720 - 20*tile_height)/2;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            DrawRectangle(x*tile_width+x_offset, y*tile_height+y_offset, tile_width, tile_height, COLOR_ARRAY[board[x][y]]);
        }
    }
}
