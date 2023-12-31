#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == '\r')
    {
        ADV();
    }
}

void STARTWORD(FILE *input) {
    START(input);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void STARTINPUT()
{
    currentWord = toKata("");
    STARTWORD(stdin);
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != '\r' && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        {
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

Word GetWord()
/*  Fungsi yang menerima sebuah parameter currentWord bertipe Word
    Kemudian mengembalikan Word tersebut */
{
    return currentWord;
}

int stringLength(char *str)
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */
{
    int len = 0;
    while (str[len] != '\0')
    {
        len = len + 1;
    }

    return len;
}

Word toKata(char *str)
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */
{
    Word kata;
    kata.Length = stringLength(str);

    for (int i = 0; i < stringLength(str); i++)
    {
        kata.TabWord[i] = str[i];
    }

    return kata;
}

void PrintWord(Word kata)
/*  I.S. kata terdefinisi
    F.S. Program akan mencetak kata ke layar dan menghitung panjang katanya */
{
    for (int i = 0; i < kata.Length; i++)
    {
        printf("%c", kata.TabWord[i]);
    }
}

boolean WordCompare(Word currentWord, Word inputWord)
/* Fungsi yang menerima dua parameter currentWord dan inputWord bertipe Word
   Kemudian mengembalikan sebuah boolean yang menyatakan apakah kedua Word adalah Word yang sama atau tidak */
{
    boolean found = false;
    int i = 0;

    if (currentWord.Length != inputWord.Length)
    {
        return found;
    }
    else
    {
        while (!found && i < currentWord.Length)
        {
            if (currentWord.TabWord[i] != inputWord.TabWord[i])
            {
                return found;
            }
            i += 1;
        }
        return !found;
    }
}

int WordToInt(Word currentWord)
/* Fungsi yang menerima parameter berupa string dan mengembalikannya dalam bentuk integer */
{
    int i = 0;
    int result = 0;
    while (i < currentWord.Length)
    {
        result = result * 10 + (currentWord.TabWord[i] - '0');
        i += 1;
    }
    return result;
}

char *WordToStr(Word kata){
    char *str = (char *)malloc(kata.Length * sizeof(char));
    for (int i = 0; i < kata.Length; i++)
    {
        str[i] = kata.TabWord[i];
    }
    str[kata.Length] = '\0';
    return str;
}

void concatWord(Word *kata1, Word kata2){
    (*kata1).TabWord[(*kata1).Length] = ' ';
    (*kata1).Length++;
    for (int i = 0; i < kata2.Length; i++)
    {
        (*kata1).TabWord[(*kata1).Length + i] = kata2.TabWord[i];
    }
    (*kata1).Length = (*kata1).Length + kata2.Length;
}


Word intToWord(int n) {
    Word num; num.Length = 0;
    if (n == 0) {
        num.TabWord[num.Length] = '0'; num.Length++;
    } else {
        while (n != 0) {
            for (int i = num.Length; i > 0; i--) {
                num.TabWord[i] = num.TabWord[i-1];
            }
            num.Length++;
            num.TabWord[0] = (n % 10) + '0';
            n = n / 10;
        }
    }
    return num;
}

Word toLower(Word kata){
    Word lower;
    lower.Length = kata.Length;
    for (int i = 0; i < kata.Length; i++)
    {
        if (kata.TabWord[i] >= 'A' && kata.TabWord[i] <= 'Z'){
            lower.TabWord[i] = kata.TabWord[i] + 32;
        } else {
            lower.TabWord[i] = kata.TabWord[i];
        }
    }
    return lower;
}

Word toUpper(Word kata){
    Word upper;
    upper.Length = kata.Length;
    for (int i = 0; i < kata.Length; i++)
    {
        if (kata.TabWord[i] >= 'a' && kata.TabWord[i] <= 'z'){
            upper.TabWord[i] = kata.TabWord[i] - 32;
        } else {
            upper.TabWord[i] = kata.TabWord[i];
        }
    }
    return upper;
}

boolean isEndWord(){
    return EndWord;
}

void GetCommand(){
    currentWord.Length = 0;
    STARTWORD(stdin);
}

Word AccessCommand(Word comm, int Idx){
    int count = 0, i = 0;
    Word out;
    out.Length = 0;

    while (i < comm.Length && count <= Idx){
        out.TabWord[out.Length] = comm.TabWord[i];
        if (comm.TabWord[i] != ' '){
            out.Length++;
        }
        if (comm.TabWord[i] == ' '){
            if (count < Idx){
                out.Length = 0;
            }
            count++;
        }
        i++;
    }
    return out;
}

Word AccessConfig(Word comm, int Idx) {
    if (Idx == 0) {
        return AccessCommand(comm, 0);
    } else if (Idx == 1) {
        boolean secondPath = false;
        Word out;
        out.Length = 0;
        for (int i = 0; i < comm.Length; i++) {
            if (secondPath) {
                out.TabWord[out.Length] = comm.TabWord[i];
                out.Length++;
            }
            if (!secondPath && comm.TabWord[i] == ' ') {
                secondPath = true;
            }
        }
        return out;
    }
}

Word AccessConfig2(Word comm, int Idx) {
    int count = 0, i = 0;
    Word out;
    out.Length = 0;

    while (i < comm.Length && count <= Idx){
        out.TabWord[out.Length] = comm.TabWord[i];
        if (comm.TabWord[i] != ';'){
            out.Length++;
        }
        if (comm.TabWord[i] == ';'){
            if (count < Idx){
                out.Length = 0;
            }
            count++;
        }
        i++;
    }
    return out;
}