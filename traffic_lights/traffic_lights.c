#include "traffic_lights.h"

#include <stddef.h>

void init(unsigned char *light)
{
    *light = *light << (sizeof(unsigned char) * 8);
}

void turn_on(unsigned char *light, unsigned char light_num)
{
    unsigned char mask = 1 << (light_num - 1);
    *light = *light | mask;
}

void turn_off(unsigned char *light, unsigned char light_num)
{
    unsigned char mask = 1 << (light_num - 1);
    mask = ~mask;
    *light = *light & mask;
}

void next_step(unsigned char *light)
{
    unsigned char mask = 1 << 1;
    if ((*light & mask) == *light)
    {
        *light = *light << 1;
        return;
    }
    mask += 1 << 3;
    if ((*light & mask) == *light)
    {
        *light = ~*light;
        return;
    }
    mask = 1 | (1 << 1);
    if ((*light & mask) == *light)
    {
        *light = mask << 1;
    }
}

void reverse(unsigned char *light)
{
    unsigned char roled = *light << 8;
    unsigned char leftPart = *light >> ((sizeof(unsigned char) * 8) - 8);
    *light = roled | leftPart;
}

void swap(unsigned char *l1, unsigned char *l2)
{
    if ((*l1 & *l2) == *l1)
        return;
    unsigned char tmp = *l1 & 1;
    *l1 = *l2 | 0;
    *l2 = tmp & 1;
}
