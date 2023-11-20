#ifndef SET_H
#define SET_H

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../Lagu/song.h"

#define CAPACITY 100

typedef struct {
    Object buffer[CAPACITY];
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

boolean SetIsFull(Set s);

void SetAdd(Set *s, Object O);

void SetRemoveElmt(Set *s, Object O);

boolean SetIsIn(Set s, Object O);

int SearchSet(Set s, Object O);

boolean SetsIsEqual(Set s1, Set s2);

Set SetUnion(Set s1, Set s2);

Set SetIntersection(Set s1, Set s2);

Set SetDifference(Set s1, Set s2);

Set SetCopy(Set s);

boolean SetIsSubset(Set s1, Set s2);

void DisplaySet(Set s);

#endif