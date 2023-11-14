# include <stdio.h>
#include "mesinkata.h"

int main(){
    printf("Masukkan kata : ");

    STARTINPUT();
    Word input = GetWord();
    ADVWORD();

    while (!EndWord)
    {
        concatWord(&input, currentWord);
        ADVWORD();
    }

    PrintWord(input);
    printf("\n");
}