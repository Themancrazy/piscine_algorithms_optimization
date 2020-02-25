#include "header.h"

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int L = 0;
	int R = n -1;
	while (L <= R)
	{
		int m = (L + R) / 2;
		if (strcmp(arts[m]->name, name) < 0)
			L = m + 1;
		else if (strcmp(arts[m]->name, name) > 0)
			R = m - 1;
		else
			return arts[m]->price;
	}
	return (-1);
}