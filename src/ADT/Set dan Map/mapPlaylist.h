#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../List Berkait/listlinier.h"

/*
MODUL Map (Implementasi dengan Kata sebagai Key dan List Berkait sebagai Value)
*/

#define Nil -1
#define MaxEl 20

typedef Word tipekey;
typedef List tipevalue;
typedef int addr;

typedef struct {
	tipekey Key;
	tipevalue Value;
} Playlist;

typedef struct {
	Playlist Elements[MaxEl];
	addr Count;
} MapPlaylist;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyPlaylist(MapPlaylist *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyPlaylist(MapPlaylist M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullPlaylist(MapPlaylist M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
void ValuePlaylist(MapPlaylist M, tipekey k, tipevalue *val);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertPlaylist(MapPlaylist *M, tipekey k, tipevalue v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeletePlaylistByName(MapPlaylist *M, tipekey k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

void DeletePlaylistByID(MapPlaylist *M, int n);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan id n mungkin anggota / bukan anggota dari M */
/* F.S. element dengan id n bukan anggota dari M */

boolean IsMemberPlaylist(MapPlaylist M, tipekey k);
/* Mengembalikan true jika k adalah member dari M */

#endif