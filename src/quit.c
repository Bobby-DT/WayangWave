#include <stdio.h>
#include "quit.h"

void quit(TabKata *Penyanyi, Map *Album, Map *Lagu, UserStorage *User, int UserID) {
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    boolean isQuitValid = false;
    do {
        GetCommand();
        if (!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord))) {
            printf("Command tidak diketahui! Jawab dengan Y/N!\n");
        } else {
            if (WordCompare(toKata("Y"), toUpper(currentWord))){
                printf("Lokasi penyimpanan data sesi sekarang (contoh: config.txt): ");
                GetCommand();
                save(currentWord, Penyanyi, Album, Lagu, User, UserID);
            }
            isQuitValid = true;
        }
    } while(!isQuitValid);
    
    printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
}

