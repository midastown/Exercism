#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {

    if (lhs == NULL || rhs == NULL || strlen(lhs) != strlen(rhs)) {
        return -1;
    }

    if (strcmp(lhs, rhs) == 0) {
        return 0;
    }

    int i, diff = 0, len = strlen(rhs);
    

    for (i=0; i<len; i++) {
        if (lhs[i] != rhs[i]) {
            diff++;
        }
    }

    return diff;
    
    
}
