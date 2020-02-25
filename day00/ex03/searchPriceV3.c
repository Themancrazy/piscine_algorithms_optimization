#include "header.h"

size_t			hash(char *input)
{
	size_t	hash = 0;
	while (*input)
	{
		hash ^= (*input << 5);
		input++;
	}
	return (hash % 95000);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict *dictionary = malloc(sizeof(struct s_dict)); 

	dictionary->capacity = capacity;
	dictionary->items = malloc(sizeof(struct s_item*) * capacity);
	int i = -1;
	while (++i <  capacity)
		dictionary->items[i] = NULL;
	return (dictionary);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item *tmp;
	struct s_item *new_node = malloc(sizeof(struct s_item));

	new_node->value = value;
	new_node->key = key;
	if (dict->items[hash(key)]) {
		tmp = dict->items[hash(key)];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		tmp->next->next = NULL;
		return (1);
	}
	dict->items[hash(key)] = new_node;
	dict->items[hash(key)]->next = NULL;
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char* key)
{
	if (!dict->items[hash(key)])
		return NULL;
	struct s_item *tmp = dict->items[hash(key)];
	if (strcmp(tmp->value->name, key) != 0)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
			if (strcmp(tmp->value->name, key) == 0)
				return (tmp->value);
		}
		return (NULL);
	}
	return (tmp->value);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	if (dictSearch(dict, name) == NULL)
		return (-1);
	return (dictSearch(dict, name)->price);
}