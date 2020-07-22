#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
    int result = 0, i, numb = (int) number;

    for (i=1; i<=numb; i++) {
        result = result + (i * i);
    }

    return (unsigned int) result;
}



unsigned int square_of_sum(unsigned int number){
    int result = 0, i, numb = (int) number;

    for (i=1; i<=numb; i++) {
        result += i;
    }
    result = result * result;
    return (unsigned int) result;
}


unsigned int difference_of_squares(unsigned int number) {
    unsigned int sumS = sum_of_squares(number);
    unsigned int sSum = square_of_sum(number);

    return sSum - sumS;
}
