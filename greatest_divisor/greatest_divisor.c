unsigned int greatest_divisor(unsigned int n)
{
    unsigned int gcd = 1;
    for (unsigned int i = 2; i < n; i++)
    {
        if (n % i == 0)
            gcd = i;
    }
    return gcd;
}
