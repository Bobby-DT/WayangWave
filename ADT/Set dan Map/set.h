#ifndef SET_H
#define SET_H

#include "../../src/boolean.h"

#define CAPACITY 100
#define Max_Length 100

typedef struct {
    char buffer[CAPACITY][Max_Length];
    int length;
} Set;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Set, maka akses elemen : */
#define Length(s) (s).length

/* *** Kreator *** */
void CreateSet(Set *s);
/* I.S. sembarang */
/* F.S. Sebuah s kosong terbentuk dengan kondisi sbb: */
/* - length bernilai 0; */
/* Proses : Melakukan alokasi, membuat sebuah skosong */

/* *** Predikat *** */
boolean isEmpty(Set s);

int length(Set s);

void add(Set *s, char Elmt[]);

void removeElmt(Set *s, char Elmt[]);

boolean isIn(Set s, char Elmt[]);

boolean isEqual(Set s1, Set s2);

Set unionSet(Set s1, Set s2);

Set intersectionSet(Set s1, Set s2);

Set setDifference(Set s1, Set s2);

Set copySet(Set s);

boolean isSubset(Set s1, Set s2);

void displaySet(Set s);



#endif
