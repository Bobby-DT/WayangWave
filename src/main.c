#include <stdlib.h>
#include <stdio.h>
#include "console.h"

int main() {
    TabKata Penyanyi;
    Queue Antrian;
    Stack Riwayat;
    Map MapPenyanyi;
    Map Album;
    MapPlaylist Playlist;

    wayangwaveStarted = false;

    MakeEmpty(&Penyanyi);
    CreateQueue(&Antrian);
    CreateEmptyStack(&Riwayat);
    CreateEmptyMap(&MapPenyanyi);
    CreateEmptyMap(&Album);
    CreateEmptyPlaylist(&Playlist);
    
    printf("Welcome to WayangWave\n");

    while (!inSession) {
        do {
            printf("> ENTER COMMAND: ");
            GetCommand();
            clear();

            if (!IsWordEq(toKata("START"), currentWord) && !IsWordEq(toKata("LOAD"), AccessCommand(currentWord, 0))) {
                printf("Command tidak bisa dieksekusi!");
            }
        } while (!IsWordEq(toKata("START"), currentWord) && !IsWordEq(toKata("LOAD"), AccessCommand(currentWord, 0)));
        
        if (IsWordEq(toKata("START"), currentWord)) start(&Penyanyi, &Antrian, &Riwayat, &MapPenyanyi, &Album, &Playlist);
        //else load();
    }
  
}
