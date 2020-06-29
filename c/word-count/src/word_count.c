#include "word_count.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int word_count(const char *input_text, word_count_word_t * words) {
    
    strncpy(words[0].text, input_text, MAX_WORD_LENGTH);
    words[0].count = 1;
    
    return 1;

    // 1) loop through the input_text char by char
    // a) char word[] = ""; empty word
    // b) check if char = space, then that means it's the end of word
    // c) check if length of char < MAX_WORD_LENGTH + 1 (because of "\0" last char)
    // 2) loop through words to see if word exist already
    // a) if it exist add 1 to count
    // b) else strncpy()
    // 3) keep a count of words of EACH INDIVIDUAL WORD as index of words
    int words_index = 0, word_index = 0, i, j;
    int len = strlen(input_text);
    char word[MAX_WORD_LENGTH + 1];


    for (i=0; i < len; i++) {
        if (input_text == ' ') {
            // add word to words if it doesn't exist
        } else {
            word[word_index] = input_text[i];
            word_index++;
        }
    }
}
