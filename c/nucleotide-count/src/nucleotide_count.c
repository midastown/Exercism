#include "nucleotide_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *count(const char *dna_strand){

    int ase = 0, cees = 0, gees = 0, tees = 0;
    int i, valid = 1, len = strlen(dna_strand);
    
    for (i=0; i<len; i++) {
        if (dna_strand[i] == 'A') {
            ase++;
        } else if (dna_strand[i] == 'C') {
            cees++;
        } else if (dna_strand[i] == 'G') {
            gees++;
        } else if (dna_strand[i] == 'T') {
            tees++;
        } else {
            valid = 0;
            break;
        }
    }

    char *result = malloc(25);

    if (valid != 1) {
        strcpy(result, "");
        return result;
    }
    sprintf(result, "A:%d ", ase);
    sprintf(result+strlen(result), "C:%d ", cees);
    sprintf(result+strlen(result), "G:%d ", gees);
    sprintf(result+strlen(result), "T:%d", tees);

    return result;
}
