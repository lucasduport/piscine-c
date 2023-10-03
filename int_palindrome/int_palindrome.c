static int my_pow(int n, int p)
{
    if (p == 0)
        return 1;
    return n * my_pow(n, p - 1);
}

static int cmpt_palindrome(int n)
{
    int res = 0;
    int count = 0;
    for (int copy = n; copy != 0; copy /= 10)
    {
        count++;
    }
    int i = 0;
    while (n != 0)
    {
        res += my_pow(10, count - 1 -i) * (n % 10);
        i++;
        n /= 10;
    }
    return res;
}

int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    int palindrome = cmpt_palindrome(n);
    if (palindrome == n)
        return 1;
    return 0;
}
