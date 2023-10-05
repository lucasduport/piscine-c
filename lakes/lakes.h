#ifndef LAKES_H
#define LAKES_H

#include <stdlib.h>

int lakes(char **map, int width, int height);

struct world
{
    char **map;
    int width;
    int height;
};

#endif /* ! LAKES_H */
