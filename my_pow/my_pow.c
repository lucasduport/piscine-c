static int opt_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return opt_pow(a * a, b / 2);
    return a * opt_pow(a * a, ( b - 1 ) / 2);
}

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
    return opt_pow(a, b);
}
