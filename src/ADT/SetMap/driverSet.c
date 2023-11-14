#include <stdlib.h>
#include <stdio.h>
#include "../../boolean.h"
#include "set.h"

int main() {
    /* KAMUS */
    Set s, s1, s2;

    /* Algoritma */
    SetCreateEmpty(&s);
    SetCreateEmpty(&s1);
    SetCreateEmpty(&s2);

    if (SetIsEmpty(s)) {
        printf("s Set kosong\n");
        printf("Panjang set kosong: %d\n", length(s));
    }

    SetAdd(&s1, "apel");
    SetAdd(&s1, "jeruk");
    SetAdd(&s1, "melon");
    SetAdd(&s1, "semangka");
    SetAdd(&s1, "jeruk");
    if (SetIsIn(s1, "apel")) {
        printf("ada apel\n");
    }
    /* s1 = {apel, jeruk, melon, semangka} */
    displaySet(s1);

    SetAdd(&s2, "melon");
    SetAdd(&s2, "pisang");
    SetAdd(&s2, "apel");
    SetAdd(&s2, "apel");
    SetAdd(&s2, "nanas");
    SetAdd(&s2, "leci");
    SetRemoveElmt(&s2, "leci");
    /* s2 = {melon, pisang, apel, nanas} */
    displaySet(s2);

    if (SetIsIn(s2, "melon")) {
        printf("Ada melon pada s2\n");
    }

    if (!SetIsIn(s2, "semangka")) {
        printf("Tidak ada semangka pada s2\n");
    }

    if (!SetsIsEqual(s1, s2)) {
        printf("s1 dan s2 tidak setara\n");
    }

    s = SetUnion(s1, s2);
    displaySet(s);

    s = SetIntersection(s1, s2);
    displaySet(s);

    s = SetDifference(s1, s2);
    displaySet(s);

    s = SetCopy(s1);
    displaySet(s);

    if (SetisSubset(s, s1)) {
        printf("s adalah subset s1\n");
    }

    SetRemoveElmt(&s, "melon");

    if (SetIsSubset(s, s1)) {
        printf("s adalah subset s1\n");
    }

    if (!SetIsSubset(s, s2)) {
        printf("s bukan subset s2\n");
    }

}
