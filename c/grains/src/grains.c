#include "grains.h"


uint64_t square(uint8_t index) {

    if (index < 1 || index > 64) {
        return 0;
    }

    int i = (int) index;
    i = i -1;

    uint64_t result = 0;
    result = 1ull << (i);

    return result;
}

uint64_t total() {
    
    int i;
    uint64_t result = 1;

    for (i=1; i<64; i++){
        result = result + (1ull << i);
    }

    return result;
}
