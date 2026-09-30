#include <time.h>

int time_in_milliseconds() {
    int time_ms = time(NULL);
    return time_ms;
}
