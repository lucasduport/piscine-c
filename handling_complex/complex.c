#include "complex.h"

void print_complex(struct complex a)
{
    if (a.img < 0)
        printf("complex(%f - %fi)", a.real, -a.img);
    else
        printf("complex(%f + %fi)", a.real, a.img);
}

struct complex neg_complex(struct complex a)
{
    a.real *= -1;
    a.img *= -1;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    a.real += b.real;
    a.img += b.img;
    return a;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    a.real -= b.real;
    a.img -= b.img;
    return a;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = (a.real * b.real - a.img * b.img);
    res.img = (a.real * b.img + b.real * a.img);
    return res;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float aa = a.real;
    float bb = a.img;
    float c = b.real;
    float d = b.img;
    struct complex res;
    res.real = (aa * c + bb * d) / (c * c + d * d);
    res.img = (bb * c - aa * d) / (c * c + d * d);
    return res;
}
