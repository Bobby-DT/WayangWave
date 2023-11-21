#include <stdio.h>
#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "map.h"
#include "set.h"

int main() {
    printf("Declaring Map . . .\nMap test;\n\n");
    Map test;

    printf("Creating Empty Map . . .\nMapCreateEmpty(&test);\n\n");
    MapCreateEmpty(&test);

    printf("MapIsEmpty(test): %d\n", MapIsEmpty(test));
    printf("MapIsFull(test): %d\n", MapIsFull(test));

    Set v;
    printf("MapInsert(&test, toKata('buah'), v);\n");
    MapInsert(&test, toKata("buah"), v);

    printf("MapIsMember(test, toKata('buah')): %d\n", MapIsMember(test, toKata("buah")));


    return 0;
}
