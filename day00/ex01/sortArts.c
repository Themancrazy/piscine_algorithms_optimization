#include "header.h"

void	sortArts(struct s_art** arts)
{
	int i = 0;
	int j = 0;
	struct s_art* tmp;
	while (arts[i + 1]) //while len(array - 1)
	{
		j = i + 1;
		while (arts[j])
		{
			if (strcmp(arts[i]->name, arts[j]->name) > 0)
			{
				tmp = arts[i];
				arts[i] = arts[j];
				arts[j] = tmp;
			}
			++j;
		}
		++i;
	}
}