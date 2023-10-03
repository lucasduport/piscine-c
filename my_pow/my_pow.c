int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (a % 2)
        return my_pow(a * a, b / 2);
    return my_pow(a * a, ( b - 1 ) / 2);
}
