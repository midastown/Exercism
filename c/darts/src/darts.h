#ifndef DARTS_H
#define DARTS_H

struct coordinates {
    float x;
    float y;
};

typedef struct coordinates coordinate_t;

int score(coordinate_t landing);
#endif
