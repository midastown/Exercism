#include "anagram.h"
#include <ctype.h>
#include <string.h>

void anagrams_for(const char *word, struct candidates *candidates) {
    
    size_t i;
    int j, k, len = strlen(word);
    
    // initialize a good boy:
    char word1[len];
    strcpy(word1, word);
    toLower(word1);

    char wordcpy[len];
    char wordcan[MAX_STR_LEN];


    for (i=0; i<candidates->count; i++) {
        strcpy(wordcpy, word1);
        strcpy(wordcan, candidates->candidate[i].word);
        toLower(wordcan);
        if (len != (int) strlen(wordcan) || strcmp(wordcan, wordcpy) == 0){

            candidates->candidate[i].is_anagram = 0;
            //memset(wordcan, 0, MAX_STR_LEN);
            continue;
        }
        for (j=0; j<len; j++) {
            for (k=0; k<len; k++){
                if (wordcan[j] == wordcpy[k]) {
                    wordcpy[k] = 0;
                    break;
                }
            }
        }
        
        candidates->candidate[i].is_anagram = isEmpty(wordcpy, len);
        //memset(wordcan, 0, MAX_STR_LEN);
    }
    

}

void toLower(char *word) {
    
    int i, len = strlen(word);

    for (i=0; i<len; i++) {
        word[i] = tolower(word[i]);
    }

    
}

int isEmpty(const char *word, int len) {

    int i;

    for (i=0; i<len; i++) {
        if (word[i] != 0)
            return 0;
    }

    return 1;
}
