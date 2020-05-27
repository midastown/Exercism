#include "armstrong_numbers.h"
#include <stdio.h>
#include <string.h>

int power(int base, int expo);

int is_armstrong_number(int candidate) {
    char str[10];
    int i, temp;
    int appli = 0;

    snprintf(str, 10, "%d", candidate);
    int len = strlen(str);

    for (i=0; i < len; i++) {
        char s = str[i];
        temp = s - '0';
        appli += power(temp, len);
    }

    if (appli == candidate) {
        return 1;
    } else {
        return 0;
    }

}

int power(int base, int expo) {
    int i, result = 1;
    for (i = 0; i < expo; i++)
        result *= base;
    return result;
 }
