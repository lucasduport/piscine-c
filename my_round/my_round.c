int my_round(float n)
{
    int isNeg = n < 0;
    if (isNeg)
    {
        n *= -1;
    }
    n += 0.5;
    int toInt = n;
    if (isNeg)
    {
        toInt *= -1;
    }
    return toInt;
}
