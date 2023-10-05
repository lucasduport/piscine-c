#include "lakes.h"

static void transformToGround(struct world *wrld, int i, int j)
{
    if (0 <= i && i <= wrld->width && 0 <= j && j <= wrld->height)
    {
        char **m = wrld->map;
        if (m[i][j] == '.')
        {
            m[i][j] = '_';
            transformToGround(wrld, i - 1, j);
            transformToGround(wrld, i + 1, j);
            transformToGround(wrld, i, j - 1);
            transformToGround(wrld, i, j + 1);
        }
    }
}

int lakes(char **map, int width, int height)
{
    struct world *wrld = malloc(sizeof(struct world));
    wrld->height = height;
    wrld->width = width;
    wrld->map = map;

    int lakes = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (map[i][i] == '.')
            {
                lakes++;
                transformToGround(wrld, i, j);
            }
        }
    }
    return lakes;
}
