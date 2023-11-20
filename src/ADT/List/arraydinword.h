#ifndef __ARRAY_DINAMIK_WORD__
#define __ARRAY_DINAMIK_WORD__

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"

#define InitialSize 10

typedef struct {
    Word *A;
    int Capacity;
    int Neff;
} ArrayDinWord;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDinWord MakeArrayDinWord();

/**
 * Destruktor
 * I.S. ArrayDinWord terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDinWord(ArrayDinWord *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDinWord(ArrayDinWord array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthArrayDinWord(ArrayDinWord array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Word GetArrayDinWord(ArrayDinWord array, int i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityArrayDinWord(ArrayDinWord array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtArrayDinWord(ArrayDinWord *array, Word el, int i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastArrayDinWord(ArrayDinWord *array, Word el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstArrayDinWord(ArrayDinWord *array, Word el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDinWord
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtArrayDinWord(ArrayDinWord *array, int i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDinWord
 * Prekondisi: array tidak kosong
 */
void DeleteLastArrayDinWord(ArrayDinWord *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDinWord
 * Prekondisi: array tidak kosong
 */
void DeleteFirstArrayDinWord(ArrayDinWord *array);

/**
 * Fungsi untuk melakukan print suatu ArrayDinWord.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDinWord(ArrayDinWord array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayDinWord.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDinWord(ArrayDinWord *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayDinWord.
 * Prekondisi: array terdefinisi
 */
ArrayDinWord CopyArrayDinWord(ArrayDinWord array);

/**
 * Fungsi untuk melakukan search suatu ArrayDinWord.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
int SearchArrayDinWord(ArrayDinWord array, Word el);

#endif