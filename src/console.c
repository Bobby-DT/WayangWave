#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void menu(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData) {
    printf(">> ");
    GetCommand();
    //clear();

    if (WordCompare(toKata("START"), currentWord) || WordCompare(toKata("LOAD"), AccessCommand(currentWord, 0))) {
        printf("WayangWave sudah dijalankan. Masukkan command HELP untuk bantuan\n\n");
    } else if (WordCompare(toKata("LIST"), AccessCommand(currentWord, 0))) {
        
    } else if (WordCompare(toKata("PLAY"), AccessCommand(currentWord, 0))) {
        
    } else if (WordCompare(toKata("QUEUE"), AccessCommand(currentWord, 0))) {
        
    } else if (WordCompare(toKata("SONG"), AccessCommand(currentWord, 0))) {
        
    } else if (WordCompare(toKata("PLAYLIST"), AccessCommand(currentWord, 0))) {
        playlist(&Penyanyi, &Antrian, &Riwayat, &Album, &Lagu, &PlaylistTitle, &PlaylistData);
    } else if (WordCompare(toKata("STATUS"), currentWord)) {
        
    } else if (WordCompare(toKata("SAVE"), AccessCommand(currentWord, 0))) {
        
    } else if (WordCompare(toKata("QUIT"), currentWord)) {
        
    } else if (WordCompare(toKata("HELP"), currentWord)) {
        // help();
    } else {
        printf("Command tidak diketahui!\n\n");
    }
}