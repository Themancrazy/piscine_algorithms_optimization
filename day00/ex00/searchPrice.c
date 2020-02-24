#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	int i = -1;
	while (arts[++i])
	{
		if (strcmp(arts[i]->name, name) == 0)
		{
			return (arts[i]->price);
		}
	}
	return (-1);
}