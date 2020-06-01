#include "resistor_color_trio.h"
#include <math.h>

struct resistor_value_t color_code(resistor_band_t* colors) {
    struct resistor_value_t resistor;
    int vae = ((colors[0] * 10) + colors[1]) * pow(10, colors[2]);

    if (vae < 1000){
        resistor.value = vae;
        resistor.unit = OHMS;
    } else {
        resistor.value = vae / 1000;
        resistor.unit = KILOOHMS;
    }
    


    return resistor;
}
