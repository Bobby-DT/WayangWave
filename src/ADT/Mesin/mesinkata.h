/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "../Mesin/mesinkarakter.h"
#include <stdio.h>

#define NMax 100
#define BLANK '\n'
#define Separator ' '

typedef struct {
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(FILE *input);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTINPUT();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

Word GetWord();
/* Fungsi yang menerima sebuah parameter currentWord bertipe Word
   Kemudian mengembalikan Word tersebut */

int stringLength (char* str);
/* Fungsi yang menerima sebuah parameter str bertipe string
   Kemudian mengembalikan panjang dari string tersebut */

Word toKata(char* str);
/* Fungsi yang menerima sebuah paramater str bertipe string
   Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */

void PrintWord(Word kata);
/*  I.S. kata terdefinisi
    F.S. Program akan mencetak kata ke layar dan menghitung panjang katanya */

boolean WordCompare(Word currentWord, Word inputWord);
/* Fungsi yang menerima dua parameter currentWord dan inputWord bertipe Word
   Kemudian mengembalikan sebuah boolean yang menyatakan apakah kedua Word adalah Word yang sama atau tidak */

int WordToInt(Word currrentWord);
/* Fungsi yang menerima parameter berupa string dan mengembalikannya dalam bentuk integer */

char *WordToStr(Word kata);
/* Fungsi yang menerima parameter berupa Word kemudian mengubah 
   dan mengembalikan kata tersebut menjadi sebuah string */

void concatWord(Word *kata1, Word kata2);
/* Menyambungkan kata kedua ke dalam kata pertama
   I.S. sembarang
   F.S. kata2 disambung ke kata pertama */

Word intToWord(int n);
/* Mengubah integer menjadi tipe data Word */

Word toLower(Word kata);
/* Mengubah kata yang merupakan huruf kapital menjadi huruf kecil */

Word toUpper(Word kata);
/* Mengubah kata yang merupakan huruf kecil menjadi huruf kapital */

boolean isEndWord();

void GetCommand();

Word AccessCommand(Word comm, int Idx);

Word AccessConfig(Word comm, int Idx);

Word AccessConfig2(Word comm, int Idx);

#endif
