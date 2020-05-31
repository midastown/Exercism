#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t* colors) {
    int i = 0;
    uint16_t result = colors[i] * 10;
    i++;
    result += colors[i];

    return result;
}
