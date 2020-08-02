#include "rational_numbers.h"
#include <math.h>

static rational_t result = {0, 0};
static const rational_t empty;

rational_t reduce(rational_t r) {

    unsigned int divisor;
    int tempn, tempd;

    
    if (r.numerator < 0)
        tempn = r.numerator * -1;
    else
        tempn = r.numerator;
    
    if (r.denominator < 0) 
        tempd = r.denominator * -1;
    else
        tempd = r.denominator;

    divisor = gcd((unsigned int) tempn, (unsigned int) tempd);

    result.numerator = r.numerator / (int) divisor;
    result.denominator = r.denominator / (int) divisor;

    if (result.denominator < 0) {
        result.numerator *= -1;
        result.denominator *= -1;
    }

    return result;
}

float exp_real(uint16_t x, rational_t r) {

    double exp = (double) r.numerator / (double) r.denominator;
    double res = pow((double) x, exp);

    return (float) res;

}

rational_t exp_rational(rational_t r, uint16_t n) {
    
    double num = (double) r.numerator;
    double den = (double) r.denominator;
    double exp = (double) n;

    num = pow(num, exp);
    den = pow(den, exp);

    result.numerator = (int) num;
    result.denominator = (int) den;

    return result;


}

rational_t absolute(rational_t r){
    if (r.numerator < 0) {
        r.numerator *= -1;
    }
    if (r.denominator < 0) {
        r.denominator *= -1;
    }
    result.numerator = r.numerator;
    result.denominator = r.denominator;

    return result;
}

rational_t divide(rational_t r1, rational_t r2) {
    
    rational_t invR2;

    if (r2.numerator < 0) {
        invR2.numerator = r2.denominator * -1;
        invR2.denominator = r2.numerator * -1;
    } else {
        invR2.numerator =  r2.denominator;
        invR2.denominator = r2.numerator;
    }

    return multiply(r1, invR2);
}

rational_t multiply(rational_t r1, rational_t r2) {
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;

    if (result.numerator == 0) {
        result.denominator = 1;
        return result;
    }

    unsigned int divisor;

    if (result.numerator < 0) {
        int temp = result.numerator * -1;
        divisor = gcd((unsigned int) temp, (unsigned int) result.denominator);
    } else {
        divisor = gcd((unsigned int) result.numerator, (unsigned int) result.denominator);
    }
    result.numerator /= divisor;
    result.denominator /= divisor;

    return result;
}



rational_t subtract(rational_t r1, rational_t r2) {

    r2.numerator *= -1;
    return add(r1, r2);
}


rational_t add(rational_t r1, rational_t r2) {

    if (r1.denominator == r2.denominator) {
        result.numerator = r1.numerator + r2.numerator;
        if (result.numerator == 0) {
            result.denominator = 1;
        } else {
            result.denominator = r1.denominator;
        }
        return result;
    }
    int den1 = r1.denominator, den2 = r2.denominator;

    r1.numerator *= den2;
    r1.denominator *= den2;
    r2.numerator *= den1;
    r2.denominator *= den1;

    result.numerator = r1.numerator + r2.numerator;
    result.denominator = r1.denominator;

    return result;

}

// this is a binary gcd algo taken from wikipedia
unsigned int gcd(unsigned int u, unsigned int v) {
    
    if (u == v)
        return u;
    if (u == 0)
        return v;
    if (v == 0)
        return u;

    // look for factor of 2
    if (~u & 1) { // if u is even
        if (v & 1) { // if v is odd 
            return gcd(u >> 1, v);
        } else { // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
        }
    }

    if (~v & 1) { // u is odd and v is even
        return gcd(u, v >> 1);
    }
    
    // reduce larger argument
    if (u > v) {
        return gcd((u - v) >> 1, v);
    }

    return gcd((v - u) >> 1, u);

}


void clear_result() {
    result = empty;
}
