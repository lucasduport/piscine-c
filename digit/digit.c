unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        res = n % 10;
        n /= 10;
    }
    return res;
}
