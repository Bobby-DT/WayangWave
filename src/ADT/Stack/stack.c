#include <stdio.h>
#include "../../boolean.h"
#include "stack.h"

void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas StackMaxEl */
/* jadi indeksnya antara 0..StackMaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == Nil);
}

boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == StackMaxEl - 1);
}

/****************** Proses semua elemen Stack ******************/
int NbElmtStack(Stack S)
/* Mengirimkan banyaknya elemen Stack; mengirimkan 0 jika Stack kosong */
{
    int count = 0;
    Song dump;
    while (!IsEmptyStack(S)) {
        PopStack(&S, &dump);
        count++;
    }
    return count;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, Song X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, Song* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = InfoTop(*S);
    Top(*S)--;
}

void InvesrseStack(Stack *Asal, Stack *Tujuan) {
    int i = 0;
    int NbAsal = NbElmtStack(*Asal);
    while (i < NbAsal && !IsFullStack(*Tujuan)) {
        Song temp;
        PopStack(Asal, &temp);
        PushStack(Tujuan, temp);
        i++;
    }
}