#include "header.h"

int main()
{
    struct s_art **art_gallery = malloc(sizeof(struct s_art*) * 15);
    char* nameList[15] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
    int priceList[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    for (int i = -1; i < 15; ++i)
    {
        art_gallery[i] = malloc(sizeof(struct s_art));
        art_gallery[i]->name = nameList[i];
        art_gallery[i]->price = priceList[i];
    }
    printf("price for \"%s\" ->\t%d\n", "C", searchPrice(art_gallery, "A"));
    return (0);
}