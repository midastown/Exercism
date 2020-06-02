#include "acronym.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *abbreviate(const char *phrase) {
    
    char *a = malloc(sizeof(char) * 20);  
    bool space = false;
    int i, len;
    int counter = 0;

    if (phrase == NULL) { 
        return NULL;
    }

    len = strlen(phrase);

    if (len == 0) {
        return NULL;
    }
    

    for (i=0; i < len; i++) {
        if (space || i == 0) {
            a[counter] = toupper(phrase[i]);
            counter++;
            space = false;
        } else if (phrase[i] == ' ' || phrase[i] == '-') {
            space = true;
        }
    }
    a[counter] = '\0';

    return a;
}
