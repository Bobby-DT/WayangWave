#include <stdio.h>
#include "quit.h"

void quit(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing, boolean *wayangwaveStarted) {
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
                save(currentWord, Penyanyi, Antrian, Riwayat, Album, Lagu, PlaylistTitle, PlaylistData, Playing);
            }
            isQuitValid = true;
        }
    } while(!isQuitValid);
    *wayangwaveStarted = false;
    printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
}

