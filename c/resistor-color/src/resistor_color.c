#include "resistor_color.h"


int color_code(resistor_band_t color) {
    const resistor_band_t container = color;
    return (int) container;
}

resistor_band_t colors() {
    const resistor_band_t actual[] = {
        BLACK,  BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
    return *actual;
}
