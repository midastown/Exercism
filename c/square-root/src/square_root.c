#include "square_root.h"

int squareRoot(int number){
    int i;

    for (i=1; i <256; i++) {
        if ( i * i ==  number) 
            return i;
    }

    return 0;
}
