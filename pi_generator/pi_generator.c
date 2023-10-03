double pi_gen(double i, double p)
{
    if (p == i)
        return 1;
    return (1 + (i / (i * 2 + 1)) * pi_gen(i + 1, p));
}

double pi_generator(int precision)
{
    if (precision <= 0)
        return 2;
    return 2.0 * pi_gen(1, precision);
}
