#include <stdlib.h>
#include <stdio.h>
#include "../../src/boolean.h"
#include "map.h"
#include "set.h"

int main() {
    Map m;
    CreateEmpty(&m);
    if (IsEmpty(m)) {
        printf("m kosong\n");
    }

    Set s;
    CreateSet(&s);
    add(&s, "apel");
    add(&s, "jeruk");
    add(&s, "nanas");

    Insert(&m, "buah", s);
    if (IsEmpty(m)) {
        printf("m kosong\n");
    } else {
        printf("m tidak kosong\n");
    }

    Set v;
    Value(m, "buah", &v);
    displaySet(v);
    
    if (IsMember(m, "buah")) {
        printf("Key buah ada dalam map\n");
    }
    if (IsMember(m, "buaha")) {
        printf("Key buaha ada dalam map\n");
    }
    if (IsMember(m, "bua")) {
        printf("Key bua ada dalam map\n");
    }
}