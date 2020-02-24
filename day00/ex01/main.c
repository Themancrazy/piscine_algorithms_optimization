#include "header.h"

int main()
{
	struct s_art **art_gallery = malloc(sizeof(struct s_art*) * 15);
	char* nameList[15] = {"O", "A", "L", "D", "M", "F", "G", "H", "I", "J", "K", "C", "E", "N", "B"};
	int priceList[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	printf("unsorted:\n");
	for (int i = 0; i < 15; i++)
	{
		art_gallery[i] = malloc(sizeof(struct s_art));
		art_gallery[i]->name = nameList[i];
		art_gallery[i]->price = priceList[i];
		printf("\t-NAME: %s\tPRICE: %d\n", art_gallery[i]->name, art_gallery[i]->price);
	}
	sortArts(art_gallery);
	return (0);
}