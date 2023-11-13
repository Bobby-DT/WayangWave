#include <stdio.h>
#include "../../boolean.h"
#include "adtList.h"

List MakeList(){
    List L;
    int i;
    for (i = 0; i < MaxEl; i++) {
        L.A[i] = Mark ;
    }

    return L ;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

boolean IsEmpty(List L){
    return (L.A[0] == Mark);
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

ElType Get(List L, IdxType i){
    return (L.A[i]);
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

void Set_SetElement(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

int Length(List L){
    int i = 0;
    while (L.A[i] != Mark && i <= MaxEl){
        i++;
    }
    return i;
}

IdxType FirstIdx(List L){
    return 0;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return (Length(L) - 1);
}

boolean IsIdxValid (List L, IdxType i){
    return (i >= 0 && i <= (MaxEl - 1));
}

boolean IsIdxEff (List L, IdxType i){
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}

boolean Search(List L, ElType X){
    IdxType i;
    boolean find = false;
    while (find == false && i <= LastIdx(L)){
        if (L.A[i] == X){
            find = true;
        }
        else {
            i+=1;
        }
    }
    return find;
}

void InsertFirst(List *L, ElType X){
    IdxType i;
    for (i = LastIdx(*L); i >= 0; i-- ){
        (*L).A[i+1] = (*L).A[i]; /*Geser semua ke kiri*/
    }

    (*L).A[FirstIdx(*L)] = X; /*Masukkin di idx pertama*/
}

void InsertAt(List *L, ElType X, IdxType i){
    IdxType j;
    for (j = LastIdx(*L); j >= i; j--) {
        (*L).A[j+1] = (*L).A[j];
    }
    (*L).A[i] = X;
}

void InsertLast(List *L, ElType X){
    if (IsEmpty(*L)){
        (*L).A[0] = X;
    }
    else{
        (*L).A[LastIdx(*L) + 1] = X;
    }
}

void DeleteFirst(List *L){
    IdxType i;
    for (i = 0; i <= LastIdx(*L); i++ ){
        (*L).A[i] = (*L).A[i+1];
    }
}

void DeleteAt(List *L, IdxType i){
    IdxType j;
    for (j = i; j <= LastIdx(*L); j++){
        (*L).A[j] = (*L).A[j+1];
    }
}

void DeleteLast(List *L){
    (*L).A[LastIdx(*L)] = Mark;
}

List Concat(List L1, List L2){
    List L;
    L = MakeList();

    IdxType i;

    for (i = 0; i < Length(L1); i++) {
        InsertLast(&L, L1.A[i]);
    }

    for (i = 0; i < Length(L2); i++) {
        InsertLast(&L, L2.A[i]);
    }
    return L;
}