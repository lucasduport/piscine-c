#include <stddef.h>
#include <stdio.h>

char best_char(int hist[], const char text[])
{
    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hist[i] > max)
        {
            max = hist[i];
        }
    }
    for (size_t j = 0; text[j] != 0; j++)
    {
        if (hist[text[j] - 'A'] == max)
        {
            hist[text[j] - 'A'] = 0;
            return text[j];
        }
    }
    return 0;
}

void freq_analysis(const char text[], const char table[])
{
    int hist[26] = { 0 };
    for (int i = 0; text[i] != 0; i++)
    {
        int c = text[i] - 'A';
        hist[c] += 1;
    }
    char associated[26] = { 0 };
    for (size_t i = 0; table[i] != 0; i++)
    {
        char c = best_char(hist, text);
        associated[c - 'A'] = table[i];
    }
    for (int i = 0; i < 26; i++)
    {
        if (associated[i] != 0)
        {
            printf("%c %c\n", i + 'A', associated[i]);
        }
    }
}
