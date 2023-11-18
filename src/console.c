#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void menu(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    printf(">> ");
    GetCommand();
    //clear();

    if (WordCompare(toKata("START"), toUpper(currentWord)) || WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0)))) {
        printf("WayangWave sudah dijalankan. Command tidak bisa dieksekusi! Masukkan command HELP untuk bantuan\n\n");
    } else if (WordCompare(toKata("LIST"), toUpper(AccessCommand(currentWord, 0)))) {
        
    } else if (WordCompare(toKata("PLAY"), toUpper(AccessCommand(currentWord, 0)))) {
        
    } else if (WordCompare(toKata("QUEUE"), toUpper(AccessCommand(currentWord, 0)))) {
        
    } else if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 0)))) {
        
    } else if (WordCompare(toKata("PLAYLIST"), toUpper(AccessCommand(currentWord, 0)))) {
        playlist(&Penyanyi, &Antrian, &Riwayat, &Album, &Lagu, &PlaylistTitle, &PlaylistData);
    } else if (WordCompare(toKata("STATUS"), toUpper(currentWord))) {
        
    } else if (WordCompare(toKata("SAVE"), toUpper(AccessCommand(currentWord, 0)))) {
        
    } else if (WordCompare(toKata("QUIT"), toUpper(currentWord))) {
        
    } else if (WordCompare(toKata("HELP"), toUpper(currentWord))) {
        help(true);
    } else {
        printf("Command tidak diketahui!\n\n");
    }
}