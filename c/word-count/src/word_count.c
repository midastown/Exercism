#include "word_count.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int word_count(const char *input_text, word_count_word_t * words) {
    
    //strncpy(words[0].text, input_text, MAX_WORD_LENGTH);
    //words[0].count = 1;
    
    //return 1;

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
    printf("%d\n", len);

    for (i=0; i < len; i++) {
        printf("value of input_text[i]: %c\n", input_text[i]);
        if (input_text[i] == ' ' || input_text[i] == '\0') {
            printf("this condition actually works");
            int yes = 0;
            for (j=0; j < words_index+1; j++) {
                if (strcmp(word, words[j].text) == 0) {
                    words[j].count++;
                    yes = 1;
                    break;
                }
            }
            if (yes==0) {
                strncpy(words[words_index].text, word, MAX_WORD_LENGTH);
                words[words_index].count = 1;
                words_index++;
                strcpy(word, "");
                word_index = 0;
            }
        } else {
            word[word_index] = input_text[i];
            word_index++;
        }
    }
    printf("this should be filled: %s\n", words[0].text);

    return words_index;
}
