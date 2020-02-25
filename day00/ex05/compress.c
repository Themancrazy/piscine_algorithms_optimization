#include "header.h"

struct s_dict      *dictInit(int capacity)
{
    struct s_dict *dict = malloc(sizeof(struct s_dict));
    dict->capacity = capacity;
    dict->items = malloc(sizeof(struct s_item*) * capacity);
    return (dict);
}

int                 dictInsert(struct s_dict *dict, char *key, int value)
{
    
}

int                 dictSearch(struct s_dict *dict, char *key)
{

}

char                *compress(char *book, struct s_dict *dict)
{

}
