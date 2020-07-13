#include "pangram.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(const char* sentence) {
    
    if (sentence == NULL || strlen(sentence) == 0) {
        return false;
    }

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int j, i, lenS = strlen(sentence), lenA = strlen(alphabet);
    char instance[lenA];
    memset(instance, 1, lenA);

    for (i=0; i<=lenS; i++) {
        char letter = tolower(sentence[i]);
        if (letter > 0x7A || letter < 0x61) {
            continue;
        }

        for (j=0; j<lenA; j++) {    
            if (letter == alphabet[j]) {
                instance[j] = 0;
                break;
            }
        }
    }

    int count = 0;

    for (j=0; j<lenA; j++) {
        count += instance[j];
    }

    if (count == 0) {
        return true;
    } else {
        return false;
    }
}
