#include <stdio.h>
#include "quit.h"

void saveSession() {
    printf("Save file berhasil disimpan.\n");
}

void quit() {
    printf("Apakah kamu ingin menyimpan data sesi sekarang (y/N)?");
    do {
        GetCommand();
        if (!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord))) {
            printf("Command tidak diketahui! Jawab dengan y/N!\n");
        } else if (WordCompare(toKata("Y"), toUpper(currentWord))){
            saveSession();
        }
    } while(!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord)));
    printf("Kamu keluar dari WayangWave.\nDdah ^_^\n");
}