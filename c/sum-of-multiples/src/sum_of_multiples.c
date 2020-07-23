#include "sum_of_multiples.h"

unsigned int sum_of_multiples(const unsigned int *multiples,
                              const size_t number_of_multiples,
                              const unsigned int up_to) {

    if (multiples == NULL || multiples[0] == 0) {
        return 0;
    }
    unsigned int result = 0;
    unsigned int i;
    size_t j;

    for (i=1; i<up_to; i++) {
        for (j=0; j<number_of_multiples; j++) {
            if (i % multiples[j] == 0){
                result += i;
                break;
            }
        }
    }

    return result;
}
