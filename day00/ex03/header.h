#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct	 	     	s_art
{
	char			*name;
	int				price;
};

struct      		s_item
{
	char			*key;
	struct s_art 	*value;
	struct s_item 	*next;
};

struct				s_dict
{
	struct s_item	**items;
	int				capacity;
};

size_t			hash(char *input);
struct s_dict	*dictInit(int capacity);
int				dictInsert(struct s_dict *dict, char *key, struct s_art *value);
struct  s_art	*dictSearch(struct s_dict *dict, char* key);
int				searchPrice(struct s_dict *dict, char *name);

#endif