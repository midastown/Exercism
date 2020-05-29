#include "darts.h"
#include <stdio.h>
#include <math.h>

int score(coordinate_t landing) {

    float dist = sqrt(pow(landing.y, 2) + pow(landing.x, 2));

    if (dist < 2) {
        return 10;
    }
    else if (dist <= 5) {
        return 5;
    }
    else if (dist <= 10) {
        return 1;
    }  

    return 0;
    
}
