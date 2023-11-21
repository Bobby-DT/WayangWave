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
    
    printf("888       888                                        888       888\n");                         
    printf("888   o   888                                        888   o   888\n");                         
    printf("888  d8b  888                                        888  d8b  888\n");                         
    printf("888 d888b 888 8888b. 888  888 8888b. 88888b.  .d88b. 888 d888b 888 8888b. 888  888 .d88b.\n");  
    printf("888d88888b888    \"88b888  888    \"88b888 \"88bd88P\"88b888d88888b888    \"88b888  888d8P  Y8b\n"); 
    printf("88888P Y88888.d888888888  888.d888888888  888888  88888888P Y88888.d888888Y88  88P88888888\n"); 
    printf("8888P   Y8888888  888Y88b 888888  888888  888Y88b 8888888P   Y8888888  888 Y8bd8P Y8b.\n");     
    printf("888P     Y888\"Y888888 \"Y88888\"Y888888888  888 \"Y88888888P     Y888\"Y888888  Y88P   \"Y8888\n");  
    printf("                          888                     888\n");                                      
    printf("                     Y8b d88P                Y8b d88P\n");                                      
    printf("                      \"Y88P\"                  \"Y88P\"\n\n");

    printf("Welcome to WayangWave\n");

    while (!wayangwaveStarted) {
        do {
            printf(">> ENTER COMMAND: ");
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
