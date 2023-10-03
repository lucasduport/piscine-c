#include "check_alphabet.h"

#include <stddef.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
        return 1;
    for (size_t i = 0; alphabet[i] != 0; i++)
    {
        int isInStr = 0;
        for (size_t j = 0; str[j] != 0 && isInStr == 0; j++)
        {
            if (alphabet[i] == str[j])
                isInStr = 1;
        }
        if (isInStr == 0)
            return 0;
    }
    return 1;
}
