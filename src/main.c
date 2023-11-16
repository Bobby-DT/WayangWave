#include <stdlib.h>
#include <stdio.h>
#include "console.h"

int main() {
    TabKata Penyanyi;
    Queue Antrian;
    Stack Riwayat;
    Map Album;
    Map Lagu;
    ArrayDinWord PlaylistTitle;
    ArrayDin PlaylistData;

    wayangwaveStarted = false;

    MakeEmpty(&Penyanyi);
    CreateQueue(&Antrian);
    CreateEmptyStack(&Riwayat);
    CreateEmptyMap(&Album);
    CreateEmptyMap(&Lagu);
    PlaylistTitle = MakeArrayDinWord();
    PlaylistData = MakeArrayDin();
    
    printf("Welcome to WayangWave\n");

    while (!inSession) {
        do {
            printf("> ENTER COMMAND: ");
            GetCommand();
            clear();

            if (!WordCompare(toKata("START"), currentWord) && !WordCompare(toKata("LOAD"), AccessCommand(currentWord, 0))) {
                printf("Command tidak bisa dieksekusi!");
            }
        } while (!WordCompare(toKata("START"), currentWord) && !WordCompare(toKata("LOAD"), AccessCommand(currentWord, 0)));
        
        if (WordCompare(toKata("START"), currentWord)) start(&Penyanyi, &Antrian, &Riwayat, &Album, &Lagu, &PlaylistTitle, &PlaylistData);
        //else load();
    }
  
}
