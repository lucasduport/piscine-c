#include "binary_cipher.h"

static char char_crypt(char c, char key)
{
    return c + key;
}

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    char *message = data;
    const char *ke = key;
    for (size_t i = 0; i < data_len; i++)
    {
        message[i] = char_crypt(message[i], ke[i % key_len]);
    }
}
