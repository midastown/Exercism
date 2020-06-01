#include "isogram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool is_isogram(const char phrase[]) {
    if (!phrase) {
        return false;
    }

    const int len = strlen(phrase);
    if (len < 2) {
        return true;
    }
    
    int counter = 0;
    char phray[len+1];
    char a = '-', b = ' ';
    for (int k=0; k<len; k++) {

        if (phrase[k] == a || phrase[k] == b) {
            continue;
        }
        phray[counter] = tolower(phrase[k]);
        counter++;
    }
    phray[counter] = '\0';
    //printf("%s\n", phray);


    char resulted[counter];
    resulted[0] = '\0';

    int i, j;

    for (i = 0; i < counter; i++) {
        char match, letter = phray[i];
        for (j = 0; j < (int) strlen(resulted); j++) {
            if (resulted[j] == '\0'){
                break;
            }
            match = resulted[j];
            if (match == letter) {
                return false;
            }
        }
        resulted[i] = letter;
        resulted[i+1] = '\0';
    }

    return true;
}
