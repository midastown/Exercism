#include "word_count.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int word_count(const char *input_text, word_count_word_t * words) {
    // 1) loop through the input_text char by char
    // a) char word[] = ""; empty word
    // b) check if char = space, then that means it's the end of word
    // c) check if length of char < MAX_WORD_LENGTH + 1 (because of "\0" last char)
    // 2) loop through words to see if word exist already
    // a) if it exist add 1 to count
    // b) else strncpy()
    // 3) keep a count of words of EACH INDIVIDUAL WORD as index of words
    char* new_input = clean_input(input_text); 
    int words_index = 0, word_index = 0, i, j;
    int len = strlen(new_input);
    char word[1024] = "";

    for (i=0; i <= len; i++) {
        if ((new_input[i] == ' ' && strlen(word) == 0) || (new_input[i] == '\0' && strlen(word) == 0)) {
            continue;
        }

        if (new_input[i] == ' ' || new_input[i] == '\0') {
            //printf("%s with count: %d\n", word);

            if (strlen(word) > MAX_WORD_LENGTH) {
                return -1;
            }
            int yes = 0;
            for (j=0; j < words_index+1; j++) {
                if (strcmp(word, words[j].text) == 0) {
                    words[j].count++;
                    yes = 1;
                    break;
                }
            }
            if (yes==0) {
                strcpy(words[words_index].text, word);
                words[words_index].count = 1;
                words_index++;
            }
            memset(word, 0, sizeof(word));
            word_index = 0;
        } else {
            word[word_index] = new_input[i];
            word_index++;
        }
    }
    free(new_input);
    if (words_index > MAX_WORDS) {
        return EXCESSIVE_NUMBER_OF_WORDS;
    } else {
        return words_index;
    }
}



char* clean_input(const char* input_text) {

    int i, j, len = strlen(input_text);
    char special[] = ",.\n!&@$%^:";
    int lenS = strlen(special);
    char *result =  malloc(len + 1);
    int quote = 0;

    for (i=0; i<=len; i++) {
        int yes = 0;

        if (input_text[i] == ' ' && quote != 0) {
            quote = 0;
            result[i] = ' ';
            continue;
        } else if (input_text[i] == '\'' && quote != 0) {
            result[quote] = ' ';
            result[i] = ' ';
            quote = 0;
            continue;
        } else if (input_text[i] == '\'') {
            quote = i;
            result[i] = input_text[i];
            continue;
        }



        for (j=0; j<lenS; j++) {
            if (input_text[i] == special[j]) {
                result[i] = ' ';
                yes = 1;
                break;
            }
        }
        if (yes == 0){
            result[i] = tolower(input_text[i]);
        }

    }

    result[i] = '\0';

    return result;
}















