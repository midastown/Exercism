#include "beer_song.h"
#include <string.h>
#include <stdio.h>

void verse(char *buffer, unsigned int verse_number) {

    char staend_plus[] = "bottles of beer on the wall";
    char staend_sing[] = "bottle of beer on the wall";
    char fmid_plus[] = "bottles of beer.\n";
    char fmid_sing[] = "bottle of beer.\n";
    char smid_plus[] = "Take one down and pass it around";
    char smid_sing[] = "Take it down and pass it around";
    char zero[] = "no more bottles of beer on the wall";
    char zero_first[] = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";

    if (verse_number == 0) {
        strcpy(buffer+strlen(buffer), zero_first);
        return;
    }

    // build verse
    sprintf(buffer+strlen(buffer), "%d ", verse_number);
    if (verse_number < 2) {
        sprintf(buffer+strlen(buffer), "%s, %d ", staend_sing, verse_number);
        sprintf(buffer+strlen(buffer), "%s", fmid_sing);
        sprintf(buffer+strlen(buffer), "%s, ", smid_sing);
        sprintf(buffer+strlen(buffer), "%s.\n", zero);
    } else {
        sprintf(buffer+strlen(buffer), "%s, %d ", staend_plus, verse_number);
        sprintf(buffer+strlen(buffer), "%s", fmid_plus);
        sprintf(buffer+strlen(buffer), "%s, %d ", smid_plus, verse_number -1);
        if ((int) verse_number - 1 < 2) {
            sprintf(buffer+strlen(buffer), "%s.\n", staend_sing);
        } else {
            sprintf(buffer+strlen(buffer), "%s.\n", staend_plus);
        }
    }
}


void sing(char *buffer, unsigned int starting_verse_number, unsigned int ending_verse_number) {

    int i;
    int start = (int) starting_verse_number;
    int finish = (int) ending_verse_number;

    for (i=start; i >= finish; i--) {
        verse(buffer, i);
        if (i != finish) {
            sprintf(buffer+strlen(buffer), "%c", '\n');
        }
    }
}

