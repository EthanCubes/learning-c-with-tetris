#include "raylib.h"

#include "header/global.h"
#include "header/clearing.h"
#include "header/user_input.h"

// This file is for piece movement, including handling user inputs

void piece_calc() {
    check_rows();
    // simulate falling pieces
    user_input();
}
