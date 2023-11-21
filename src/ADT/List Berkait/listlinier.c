/* File : listlinier.C */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListLinier(ListLinier L)
/* Mengirim true jika list kosong */
{
    return First(L) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListLinier(ListLinier *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
address AlokasiListLinier(Song X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    address P = (address)malloc(1 * sizeof(ElmtListLinier));
    if (P != NULL)
    {
        Info(P) = X;
        Next(P) = NULL;
        return P;
    } else
    {
        return NULL;
    }
}

void DealokasiListLinier(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchListLinier(ListLinier L, Song X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    address P;
    boolean bFound = false;

    if (!IsEmptyListLinier(L))
    {
        P = First(L);
        while (!bFound && P != NULL)
        {
            if (SongIsEqual(Info(P), X))
            {
                bFound = true;
            }
            else
            {
                P = Next(P);
            }
        }

        if (bFound)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListLinier(ListLinier *L, Song X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = AlokasiListLinier(X);
    if (P != NULL)
    {
        InsertFirstListLinier(L, P);
    }
}

void InsVLastListLinier(ListLinier *L, Song X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = AlokasiListLinier(X);
    if (P != NULL)
    {
        InsertLastListLinier(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListLinier(ListLinier *L, Song *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    DealokasiListLinier(&P);
}

void DelVLastListLinier(ListLinier *L, Song *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    address Prec = NULL;

    while (Next(P) != NULL)
    {
        Prec = P;
        P = Next(P);
    }

    *X = Info(P);
    if (Prec != NULL)
    {
        Next(Prec) = NULL;
    }
    else
    {
        First(*L) = NULL;
    }
    DealokasiListLinier(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListLinier(ListLinier *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterListLinier(ListLinier *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastListLinier(ListLinier *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;

    if (IsEmptyListLinier(*L))
    {
        InsertFirstListLinier(L, P);
    }
    else
    {
        Last = First(*L);
        while (Next(Last) != NULL)
        {
            Last = Next(Last);
        }
        InsertAfterListLinier(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListLinier(ListLinier *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NULL;
}

void DelPListLinier(ListLinier *L, Song X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address Prec;
    address P;
    boolean bFound = false;

    if (!IsEmptyListLinier(*L))
    {
        if (SongIsEqual(Info(First(*L)), X))
        {
            DelFirstListLinier(L, &P);
            DealokasiListLinier(&P);
        }
        else
        {
            P = First(*L);
            while (!bFound && P != NULL)
            {
                if (SongIsEqual(Info(P), X))
                {
                    bFound = true;
                }
                else
                {
                    Prec = P;
                    P = Next(P);
                }
            }

            if (bFound)
            {
                DelAfterListLinier(L, &P, Prec);
                DealokasiListLinier(&P);
            }
        }
    }
}

void DelLastListLinier(ListLinier *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address Last = First(*L);
    address PrecLast = NULL;

    while (Next(Last) != NULL)
    {
        PrecLast = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (PrecLast == NULL)
    {
        First(*L) = NULL;
    }
    else
    {
        Next(PrecLast) = NULL;
    }
}

void DelAfterListLinier(ListLinier *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = NULL;
}

address addrAtListLinier(ListLinier *L, int Idx) {
    int count = 1;
    address P = First(*L);
    while (count < Idx) {
        P = Next(P);
        count++;
    }
    return P;
}

Song getValAtListLinier(ListLinier *L, int Idx) {
    return Info(addrAtListLinier(L, Idx));
}

void setValAtListLinier(ListLinier *L, int Idx, Song set) {
    int count = 1;
    address P = First(*L);
    while (count < Idx) {
        P = Next(P);
        count++;
    }
    Info(P) = set;
}

void DelAtListLinier(ListLinier *L, int Idx) {
    int count = 1;
    address P = First(*L);
    while (count < Idx - 1) {
        P = Next(P);
        count++;
    }
    address Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(Pdel) = NULL;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoListLinier(ListLinier L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    boolean isFirst = true;

    printf("[");
    if (!IsEmptyListLinier(L))
    {
        P = First(L);
        while (P != NULL)
        {
            if (!isFirst)
            {
                printf(",");
            }
            printf("<%d, %d, %d, %d>", Info(P).PenyanyiID, Info(P).AlbumID, Info(P).LaguID, Info(P).PlaylistID);
            isFirst = false;

            P = Next(P);
        }
    }
    printf("]");
}
int NumberElmtListLinier(ListLinier L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;
    address P;

    if (!IsEmptyListLinier(L))
    {
        P = First(L);
        while (P != NULL)
        {
            cnt++;
            P = Next(P);
        }
    }

    return cnt;
}

/****************** PROSES TERHADAP LIST ******************/
void InversListLinier(ListLinier *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P;
    address Prec = NULL;
    address Succ;

    if (!IsEmptyListLinier(*L))
    {
        P = First(*L);
        while (P != NULL)
        {
            Succ = Next(P);
            Next(P) = Prec;
            Prec = P;
            P = Succ;
        }
        First(*L) = Prec;
    }
}

void KonkatListLinier(ListLinier *L1, ListLinier *L2, ListLinier *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address Last1;

    CreateEmptyListLinier(L3);
    if (IsEmptyListLinier(*L1))
    {
        First(*L3) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != NULL)
        {
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);
    }

    First(*L1) = NULL;
    First(*L2) = NULL;
}
