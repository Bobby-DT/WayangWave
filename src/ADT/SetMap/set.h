#ifndef _SET_H
#define _SET_H

#include "../../boolean.h"

#define CAPACITY 100

typedef struct {
    Word buffer[CAPACITY];
    int length;
} Set;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Set, maka akses elemen : */
#define Length(s) (s).length

/* *** Kreator *** */
void SetCreateEmpty(Set *s);
/* I.S. sembarang */
/* F.S. Sebuah s kosong terbentuk dengan kondisi sbb: */
/* - length bernilai 0; */
/* Proses : Melakukan alokasi, membuat sebuah skosong */

/* *** Predikat *** */
boolean SetIsEmpty(Set s);

int SetLength(Set s);

void SetAdd(Set *s, Word);

void SetRemoveElmt(Set *s, Word);

boolean SetIsIn(Set s, Word);

boolean SetsIsEqual(Set s1, Set s2);

Set SetUnion(Set s1, Set s2);

Set SetIntersection(Set s1, Set s2);

Set SetDifference(Set s1, Set s2);

Set SetCopy(Set s);

boolean SetIsSubset(Set s1, Set s2);

void DisplaySet(Set s);



#endif
