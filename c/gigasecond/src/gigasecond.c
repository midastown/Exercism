#include "gigasecond.h"
#include <stdio.h>

time_t gigasecond_after(time_t value) {
    value += 1000000000;
    return value;
}
