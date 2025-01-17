#ifndef RATIONAL_NUMBERS
#define RATIONAL_NUMBERS

#include <stdint.h>

typedef struct {
    int numerator;
    int denominator;
} rational_t;

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r);
rational_t exp_rational(rational_t r, uint16_t n);
rational_t reduce(rational_t r);
unsigned int gcd(unsigned int u, unsigned int v);
float exp_real(uint16_t x, rational_t r);

void clear_result();


#endif
