#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct      s_art
{
	char	*name;
	int		price;
};

int		searchPrice(struct s_art **arts, int n, char *name);

#endif