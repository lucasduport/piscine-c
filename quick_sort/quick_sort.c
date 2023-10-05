static void swap(int *tab, int i, int j)
{
    int tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
}

static int divideArr(int *tab, int lo, int hi, int p)
{
    int j = lo - 1;
    for (int i = lo; i < hi + 1; i++)
    {
        if (tab[i] < p)
        {
            j++;
            swap(tab, i, j);
        }
    }
    swap(tab, hi, j + 1);
    return j + 1;
}

static void qs(int *tab, int lo, int hi)
{
    if (lo < hi)
    {
        int p = divideArr(tab, lo, hi, tab[hi]);
        qs(tab, lo, p - 1);
        qs(tab, p + 1, hi);
    }
}

void quicksort(int *tab, int len)
{
    if (tab == 0 || len == 0)
        return;
    qs(tab, 0, len - 1);
}
