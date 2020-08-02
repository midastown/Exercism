#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

char *to_roman_numeral(unsigned int number) {
    
    char *result = malloc(sizeof(char) * 14);
    int i = 0;

    while (number > 0) {
        if (number >= 1000) {
            number -= 1000;
            result[i] = 'M';
            i++;
        } else if (number >= 900) {
            number -= 900;
            strcpy(result + i, "CM");
            i += 2;
        } else if (number >= 500) {
            number -= 500;
            result[i] = 'D';
            i++;
        } else if (number >= 400) {
            number -= 400;
            strcpy(result + i, "CD");
            i += 2;
        } else if (number >= 100) {
            number -= 100;
            result[i] = 'C';
            i++;
        } else if (number >= 90) {
            number -= 90;
            strcpy(result + i, "XC");
            i += 2;
        } else if (number >= 50) {
            number -= 50;
            result[i] = 'L';
            i++;
        } else if (number >= 40) {
            number -= 40;
            strcpy(result + i, "XL");
            i += 2;
        } else if (number >= 10) {
            number -= 10;
            result[i] = 'X';
            i++;
        } else if (number >= 9) {
            number -= 9;
            strcpy(result + i, "IX");
            i += 2;
        } else if (number >= 5) {
            number -= 5;
            result[i] = 'V';
            i++;
        } else if (number >= 4) {
            number -= 4;
            strcpy(result + i, "IV");
            i += 2;
        } else {
            number -= 1;
            result[i] = 'I';
            i++;
        }
    }

    result[i] = '\0';

    return result;
}
