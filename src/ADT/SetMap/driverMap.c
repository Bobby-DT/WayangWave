#include <stdlib.h>
#include <stdio.h>
#include "../../boolean.h"
#include "map.h"
#include "set.h"

int main() {
    Map m;
    MapCreateEmpty(&m);
    if (IsEmpty(m)) {
        printf("m kosong\n");
    } 


    Set s;
    SetCreateEmpty(&s);
    SetAdd(&s, "apel");
    SetAdd(&s, "jeruk");
    SetAdd(&s, "nanas");

    MapInsert(&m, "buah", s);
    if (MapIsEmpty(m)) {
        printf("m kosong\n");
    } else {
        printf("m tidak kosong\n");
    }

    if (!MapIsFull(m)) {
        printf("m tidak penuh\n");
    }

    Set v;
    MapValue(m, "buah", &v);
    displaySet(v);
    
    if (MapIsMember(m, "buah")) {
        printf("Key buah ada dalam map\n");
    }
    if (MapIsMember(m, "sayur")) {
        printf("Key sayur ada dalam map\n");
    }
    if (MapIsMember(m, "nasi")) {
        printf("Key nasi tidak ada dalam map\n");
    }
    
    MapDelete(&m, "buah");

    if (!MapIsMember(m, "buah")) {
        printf("Key buah tidak ada dalam map\n");
    }

    
}
