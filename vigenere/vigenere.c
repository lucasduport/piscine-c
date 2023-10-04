#include "vigenere.h"

#include <stddef.h>

static size_t my_strlen(const char *s)
{
    size_t count = 0;
    for (size_t i = 0; s[i] != 0; i++)
    {
        count++;
    }
    return count;
}

static char isMaj(char c)
{
    return c >= 'A' && c <= 'Z';
}

static char toMaj(char c)
{
    if (c >= 'a' && c <= 'z')
        return c + ('A' - 'a');
    return c;
}
void cipher(const char *key, const char *msg, char *res)
{
    size_t keyL = my_strlen(key);
    size_t j = 0;
    for (size_t i = 0; msg[i] != 0; i++)
    {
        char msgCaps = toMaj(msg[i]);
        if (isMaj(msgCaps))
            res[i] = 'A' + (msgCaps + toMaj(key[j++ % (keyL)])) % 26;
        else
            res[i] = msg[i];
    }
}

void decipher(const char *key, const char *msg, char *res)
{
    size_t keyL = my_strlen(key);
    size_t j = 0;
    for (size_t i = 0; msg[i] != 0; i++)
    {
        char msgCaps = toMaj(msg[i]);
        if (isMaj(msgCaps))
            res[i] = 'A' + ((msgCaps - toMaj(key[j++ % (keyL)]) + 26) % 26);
        else
            res[i] = msg[i];
    }
}
