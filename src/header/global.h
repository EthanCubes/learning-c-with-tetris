#ifndef GLOBAL
#define GLOBAL

#include <stdbool>

extern bool currently_falling;

extern int board[10][20]; // X, Y, there are 10 possible x and 20 possible y
extern int tetrimino_spots[4][2]; // 4 different squares in tetriminos, 2 coordinates for each

#endif
