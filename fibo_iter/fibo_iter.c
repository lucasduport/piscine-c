unsigned long fibo_iter(unsigned long n)
{
    unsigned long n1 = 0;
    unsigned long n2 = 1;
    if (n == 0)
        return n1;
    if (n == 1)
        return n2;
    for (unsigned long i = 1; i < n; i++)
    {
        unsigned long tmp = n2;
        n2 += n1;
        n1 = tmp;
    }
    return n2;
}
