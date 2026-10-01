#include <time.h>
#include "raylib.h"

int time_in_milliseconds() {
    long long time_ms = (long long)(GetTime() * 1000.0);
    return time_ms;
}
