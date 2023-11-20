#include <stdio.h>
#include <stdlib.h>
#include "./ADT/Mesin/mesinkata.h"
#include "console.h"

int main() {
    TabKata Penyanyi;
    Queue Antrian;
    Stack Riwayat;
    Map Album;
    Map Lagu;
    ArrayDinWord PlaylistTitle;
    ArrayDin PlaylistData;
    Lagu Playing;

    wayangwaveStarted = false;

    MakeEmpty(&Penyanyi);
    CreateQueue(&Antrian);
    CreateEmptyStack(&Riwayat);
    MapCreateEmpty(&Album);
    MapCreateEmpty(&Lagu);
    PlaylistTitle = MakeArrayDinWord();
    PlaylistData = MakeArrayDin();
    CreateEmptyLagu(&Playing);
    
    printf("Welcome to WayangWave\n");

    while (!wayangwaveStarted) {
        do {
            printf("> ENTER COMMAND: ");
            GetCommand();
            clear();

            if (WordCompare(toKata("HELP"), toUpper(currentWord))) {
                help(false);
            } else if (!WordCompare(toKata("START"), toUpper(currentWord)) && !WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0)))) {
                printf("Command tidak bisa dieksekusi!\n\n");
            }
        } while (!WordCompare(toKata("START"), toUpper(currentWord)) && !WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0))) && !WordCompare(toKata("HELP"), toUpper(currentWord)));
        
        if (WordCompare(toKata("START"), toUpper(currentWord))) {
            start(toKata("config.txt"), &Penyanyi, &Antrian, &Riwayat, &Album, &Lagu, &PlaylistTitle, &PlaylistData, &Playing);
        } else if (WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0)))) {
            start(AccessCommand(currentWord, 1), &Penyanyi, &Antrian, &Riwayat, &Album, &Lagu, &PlaylistTitle, &PlaylistData, &Playing);
        }
    }
    if (wayangwaveStarted) {
        while (wayangwaveStarted) {
            menu(&Penyanyi, &Antrian, &Riwayat, &Album, &Lagu, &PlaylistTitle, &PlaylistData, &Playing);
        }
    } else {
        printf("WayangWave gagal dijalankan.\n\n");
    }
}
