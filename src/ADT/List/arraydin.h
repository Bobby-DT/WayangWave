#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../List Berkait/listlinier.h"

#define InitialSize 10

typedef struct {
    ListLinier *A;
    int Capacity;
    int Neff;
} ArrayDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDin(ArrayDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayDin(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ListLinier GetArrayDin(ArrayDin array, int i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrayDin(ArrayDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtArrayDin(ArrayDin *array, ListLinier el, int i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastArrayDin(ArrayDin *array, ListLinier el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstArrayDin(ArrayDin *array, ListLinier el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtArrayDin(ArrayDin *array, int i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLastArrayDin(ArrayDin *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirstArrayDin(ArrayDin *array);

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
// void PrintArrayDin(ArrayDin array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array);

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
//int SearchArrayDin(ArrayDin array, ListLinier el);

#endif