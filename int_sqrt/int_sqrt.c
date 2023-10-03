int int_sqrt(int n)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    int sqrt = 1;
    for (; sqrt * sqrt < n; sqrt++)
    {
        continue;
    }
    if (sqrt * sqrt == n)
        return sqrt;
    return sqrt - 1;
}
