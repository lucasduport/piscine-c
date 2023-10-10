#include "hash_map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *h = malloc(sizeof(struct hash_map));
    if (h == NULL)
        return NULL;
    h->data = calloc(sizeof(struct pair_list), size);
    if (h->data == NULL)
        return NULL;
    h->size = size;
    return h;
}

static void *hash_map_update(const struct hash_map *hash_map, const char *key,
                             char *value)
{
    if (hash_map == NULL || hash_map->size == 0)
        return NULL;
    size_t index = hash(key);
    if (index >= hash_map->size)
        index = index % hash_map->size;
    struct pair_list *chained = hash_map->data[index];
    while (chained != NULL)
    {
        if (strcmp(chained->key, key) == 0)
        {
            chained->value = value;
        }
        chained = chained->next;
    }
    return NULL;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (hash_map == NULL || hash_map->size == 0)
        return false;
    if (hash_map_get(hash_map, key) != NULL)
    {
        *updated = true;
        hash_map_update(hash_map, key, value);
        return true;
    }
    size_t index = hash(key);
    if (index >= hash_map->size)
        index = index % hash_map->size;
    struct pair_list *new = malloc(sizeof(struct pair_list));
    if (new == NULL)
    {
        return false;
    }
    *updated = false;
    struct pair_list *list = hash_map->data[index];
    new->key = key;
    new->value = value;
    new->next = list;
    hash_map->data[index] = new;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map == NULL)
        return;
    if (hash_map->data == NULL)
    {
        free(hash_map->data);
        return;
    }
    struct pair_list **l = hash_map->data;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *chained = l[i];
        while (chained != NULL)
        {
            struct pair_list *tmp = chained->next;
            free(chained);
            chained = tmp;
        }
    }
    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(struct hash_map *hash_map)
{
    struct pair_list **l = hash_map->data;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *chained = l[i];
        if (chained != NULL)
        {
            printf("%s: %s", chained->key, chained->value);
            while (chained->next != NULL)
            {
                chained = chained->next;
                printf(", %s: %s", chained->key, chained->value);
            }
            printf("\n");
        }
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || hash_map->size == 0)
        return NULL;
    size_t index = hash(key);
    if (index >= hash_map->size)
        index = index % hash_map->size;
    struct pair_list *chained = hash_map->data[index];
    while (chained != NULL)
    {
        if (strcmp(chained->key, key) == 0)
            return chained->value;
        chained = chained->next;
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || hash_map->size == 0)
        return false;
    size_t index = hash(key);
    if (index >= hash_map->size)
        index = index % hash_map->size;
    struct pair_list *l = hash_map->data[index];
    if (l == NULL)
        return false;
    if (l->key == key)
    {
        hash_map->data[index] = l->next;
        free(l);
        return true;
    }
    while (l->next != NULL)
    {
        if (strcmp(l->next->key, key) == 0)
        {
            struct pair_list *toFree = l->next;
            l->next = l->next->next;
            free(toFree);
            return true;
        }
        l = l->next;
    }
    return false;
}
