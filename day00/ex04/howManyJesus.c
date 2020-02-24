#include "header.h"

int     howManyJesus(char* bible, char* jesus)
{
	int prime = 11;
	int len_pattern = strlen(jesus);
	int len_text = strlen(bible);
	int i, j;
	int possible_ascii = 256;
	int hash_pattern = 0;
	int hash_text = 0;
	int h = 1;
	int occurances = 0;

	for (i = 0; i < len_pattern - 1; i++)  
        h = (h * possible_ascii) % prime;  
	for (i = 0;i < len_pattern;i++)
	{
		hash_pattern = (possible_ascii * hash_pattern + jesus[i]) % prime;
		hash_text = (possible_ascii * hash_text + bible[i]) % prime;
	}
	for (i = 0;i < len_text - len_pattern;i++)
	{
		if (hash_pattern == hash_text)
		{
			for (j = 0;j < len_pattern;j++)
			{
				if (bible[i+j] != jesus[j])
					break ;
			}
			if (j == len_pattern)
				++occurances;
		}
		if (i < len_text - len_pattern)
		{
			hash_text = (possible_ascii * (hash_text - bible[i] * h) + bible[i + len_pattern]) % prime;
			if (hash_text < 0)
				hash_text += prime;
		}
	}
	return occurances;
}