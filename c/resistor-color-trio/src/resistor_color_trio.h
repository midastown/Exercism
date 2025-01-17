#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#define OHMS 1
#define KILOOHMS 1000


typedef enum {
    BLACK = 0,
    BROWN = 1,
    RED = 2,
    ORANGE = 3,
    YELLOW = 4,
    GREEN = 5,
    BLUE = 6,
    VIOLET = 7,
    GREY = 8,
    WHITE = 9
} resistor_band_t;

struct resistor_value_t {
    int value;
    int unit;
};

struct resistor_value_t color_code(resistor_band_t*);

#endif
