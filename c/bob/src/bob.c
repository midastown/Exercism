#include "bob.h"
#include <string.h>

char *hey_bob(char *greeting) {

    if (isYell(greeting) == 1) {
        if (greeting[strlen(greeting) - 1] == '?') {
            return "Calm down, I know what I'm doing!";
        } else {
            return "Whoa, chill out!";
        }
    }
    if (isQuestion(greeting) == 1)
        return "Sure.";

    if (isPassive(greeting) == 1) 
        return "Fine. Be that way!"; 

    return "Whatever.";
}

int isQuestion(char *greeting) {

    int mark = 0, i, len = strlen(greeting);

    if (greeting[len - 1] == '?')
        return 1;

    for (i=0; i<len; i++) {
        if (greeting[i] == '?') {
            mark = 1;
        } else if (mark == 1 && greeting[i] != ' ') {
            return 0;
        }
    }
    return mark;
}


int isPassive(char *greeting) {

   int i, len = strlen(greeting);

   if (len == 0)
        return 1;

   for (i=0; i<len; i++) {
       if ((greeting[i] >= 0x61 && greeting[i] <= 0x7A) || (greeting[i] >= 0x41 && greeting[i] <= 0x5A) || (greeting[i] >= 0x30 && greeting[i] <= 0x39))
           return 0;
   }
   return 1;
}


int isYell(char *greeting) {

    int maj = 0, len = strlen(greeting);
    int i;

    for (i=0; i<len; i++) {
        if (greeting[i] >= 0x61 && greeting[i] <= 0x7A) {
            return 0;
        } else if (greeting[i] >= 0x41 && greeting[i] <= 0x5A) {
            maj = 1;
        }
    }

    if (maj == 1) {
        return 1;
    }
    return 0;
}
