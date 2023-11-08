#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void menu(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *MapPenyanyi, Map *Album) {
    printf(">> ");
    GetCommand();
    //clear();

    if (IsWordEq(toKata("START"), currentWord) || IsWordEq(toKata("LOAD"), AccessCommand(currentWord, 0))) {
        printf("WayangWave sudah dijalankan. Masukkan command HELP untuk bantuan\n\n");
    } else if (IsWordEq(toKata("LIST"), AccessCommand(currentWord, 0))) {
        
    } else if (IsWordEq(toKata("PLAY"), AccessCommand(currentWord, 0))) {
        
    } else if (IsWordEq(toKata("QUEUE"), AccessCommand(currentWord, 0))) {
        
    } else if (IsWordEq(toKata("SONG"), AccessCommand(currentWord, 0))) {
        
    } else if (IsWordEq(toKata("PLAYLIST"), AccessCommand(currentWord, 0))) {
        
    } else if (IsWordEq(toKata("STATUS"), currentWord)) {
        
    } else if (IsWordEq(toKata("SAVE"), AccessCommand(currentWord, 0))) {
        
    } else if (IsWordEq(toKata("QUIT"), currentWord)) {
        
    } else if (IsWordEq(toKata("HELP"), currentWord)) {
        // help();
    } else {
        printf("Command tidak diketahui!\n\n");
    }
}