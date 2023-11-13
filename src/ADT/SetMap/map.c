#include <stdio.h>
#include "../../src/boolean.h"
#include "map.h"
#include "set.h"

Set Undefined;
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
{
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M) {
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M)
{
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
void Value(Map M, keytype k, valuetype *val)
{
    boolean KeyFound = false;
    int i = 0;
    
    while (!KeyFound && i < M.Count)  {
        if (M.Elements[i].Key == k) {
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

void Insert(Map *M, keytype k, valuetype v)
{
    infotype El;
    if (!IsMember(*M, k))
    {
        if (IsEmpty(*M)) {
            (*M).Count = 0;
        }
        copyKey(k, El.Key); // Tipe key (String) perlu fungsi copyKey
        El.Value = v; // Tipe set bisa langsung diassign
        (*M).Elements[(*M).Count] = El;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k) 
{
    int i = 0;
    boolean found = false;
    while (!found && i < (*M).Count) {
        if ((*M).Elements[i].Key == k) {
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

boolean IsMember(Map M, keytype k) {
    boolean found = false;
    int i = 0;

    while (!found && i < M.Count)  {
        if (equalKey(M.Elements[i].Key, k)) {
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */


/* ********** Operator Terkait Key ********* */

void copyKey(char *key1, char *key2) {
    /* Copy key1 ke key2 */
    int i;
    for (i = 0; key1[i] != '\0'; i++) {
        key2[i] = key1[i];
    } 
    key2[i] = '\0';
}

boolean equalKey(char *key1, char *key2) {
    /* Compare key1 dengan key2 */
    int i;
    boolean equal = true;
    for (i = 0; key1[i] != '\0'; i++) {
        if (key1[i] != key2[i]) {
            equal = false;
        }
    } 
    if (key1[i] != key2[i]) {
        equal = false;
    }
    return equal;
}

