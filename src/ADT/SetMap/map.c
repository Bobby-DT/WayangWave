#include <stdio.h>
#include "../../boolean.h"
#include "map.h"
#include "set.h"

Set Undefined;
/* *** Konstruktor/Kreator *** */
void MapCreateEmpty(Map *M)
{
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean MapIsEmpty(Map M) {
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean MapIsFull(Map M)
{
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
void MapValue(Map M, Word k, Set *val)
{
    boolean KeyFound = false;
    int i = 0;
    
    while (!KeyFound && i < M.Count)  {
        if (WordCompare(M.Elements[i].Key, k)) {
            *val = M.Elements[i].Value;
            KeyFound = true;
        }
        i++;
    }
    if (!KeyFound) {
        Undefined.length = -1;
        *val = Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void MapInsert(Map *M, Word k, Set v)
{
    dictionary El;
    if (!MapIsMember(*M, k))
    {
        if (MapIsEmpty(*M)) {
            (*M).Count = 0;
        }
        El.Key = k;
        El.Value = v; // Tipe set bisa langsung diassign
        (*M).Elements[(*M).Count] = El;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void MapDelete(Map *M, Word k) 
{
    int i = 0;
    boolean found = false;
    while (!found && i < (*M).Count) {
        if (WordCompare((*M).Elements[i].Key, k)) {
            for (int j = i; j < ((*M).Count-1); j++) {
                (*M).Elements[j] = (*M).Elements[j+1];
            }
            (*M).Count--;
            found = true;
        }
        i++;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean MapIsMember(Map M, Word k) {
    boolean found = false;
    int i = 0;

    while (!found && i < M.Count)  {
        if (WordCompare(M.Elements[i].Key, k)) {
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */

int searchMap(Map M, Word k) {
    int i = 0;
    for (int i = 0; i < M.Count; i++)  {
        if (WordCompare(M.Elements[i].Key, k)) {
            return i;
        }
    }
    return -1;
}


