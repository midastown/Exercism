#include "resistor_color.h"

resistor_band_t actual[] = {
        BLACK,  BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
};

int color_code(resistor_band_t color) {
    return (int) color;
}

resistor_band_t* colors() {
    return actual;
}
