#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna) {
    
    int i, len = strlen(dna);
    char *rna = malloc(len);

    for (i=0; i<len; i++) {
        if (dna[i] == 'G') {
            rna[i] = 'C';
        } else if (dna[i] == 'C') {
            rna[i] = 'G';
        } else if (dna[i] == 'T') {
            rna[i] = 'A';
        } else if (dna[i] == 'A') {
            rna[i] = 'U';
        } else {
            return NULL;
        }
    }

    return rna;



}
