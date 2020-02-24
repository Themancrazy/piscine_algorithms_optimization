#include "header.h"

int main()
{
	struct s_art **art_gallery = malloc(sizeof(struct s_art*) * 15);
	struct s_dict *dictionary = dictInit(15);
	char* nameList[15] = {"O", "A", "L", "D", "M", "F", "G", "H", "I", "J", "K", "C", "E", "N", "B"};
	int priceList[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	for (int i = 0; i < 15; i++)
	{
		art_gallery[i] = malloc(sizeof(struct s_art));
		art_gallery[i]->name = nameList[i];
		art_gallery[i]->price = priceList[i];
		dictInsert(dictionary, nameList[i], art_gallery[i]);
	}
	printf("hash result for \"D\"->\t%d\n", searchPrice(dictionary, "sofeoqnoeqbfn"));
	return (0);
}