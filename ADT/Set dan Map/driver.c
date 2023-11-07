#include <stdlib.h>
#include <stdio.h>
#include "../../src/boolean.h"
#include "set.h"

int main() {
    /* KAMUS */
    Set s, s1, s2;

    /* Algoritma */
    CreateSet(&s);
    CreateSet(&s1);
    CreateSet(&s2);

    if (isEmpty(s)) {
        printf("s Set kosong\n");
        printf("Panjang set kosong: %d\n", length(s));
    }

    add(&s1, "apel");
    add(&s1, "jeruk");
    add(&s1, "melon");
    add(&s1, "semangka");
    add(&s1, "jeruk");
    if (isIn(s1, "apel")) {
        printf("ada apel\n");
    }
    /* s1 = {apel, jeruk, melon, semangka} */
    displaySet(s1);

    add(&s2, "melon");
    add(&s2, "pisang");
    add(&s2, "apel");
    add(&s2, "apel");
    add(&s2, "nanas");
    add(&s2, "leci");
    removeElmt(&s2, "leci");
    /* s2 = {melon, pisang, apel, nanas} */
    displaySet(s2);

    if (isIn(s2, "melon")) {
        printf("Ada melon pada s2\n");
    }

    if (!isIn(s2, "semangka")) {
        printf("Tidak ada semangka pada s2\n");
    }

    if (!isEqual(s1, s2)) {
        printf("s1 dan s2 tidak setara\n");
    }

    s = unionSet(s1, s2);
    displaySet(s);

    s = intersectionSet(s1, s2);
    displaySet(s);

    s = setDifference(s1, s2);
    displaySet(s);

    s = copySet(s1);
    displaySet(s);

    if (isSubset(s, s1)) {
        printf("s adalah subset s1\n");
    }

    removeElmt(&s, "melon");

    if (isSubset(s, s1)) {
        printf("s adalah subset s1\n");
    }

    if (!isSubset(s, s2)) {
        printf("s bukan subset s2\n");
    }

}
