#include <stdio.h>
#include <stdlib.h>
#include "./ADT/Mesin/mesinkata.h"
#include "console.h"

void userManagement(UserStorage *User, Object *currentUser, boolean *wayangwaveStarted, boolean *quitAfterLoaded) {
    while (!(*wayangwaveStarted) && !(*quitAfterLoaded)) {
        printf(">> ENTER COMMAND: ");
        GetCommand();
        if (WordCompare(toKata("REGISTER"), toUpper(currentWord))) {
            printf("Masukkan username baru untuk WayangWave : ");
            GetCommand();
            if (searchUser(User, currentWord) == -1) {
                int UserID = createNewUser(User, currentWord);
                printf("Berhasil mendaftarkan pengguna. Selamat datang, %s!\n\n", WordToStr(currentWord));
                *wayangwaveStarted = true;
                *currentUser = CreateObject(UserID, currentWord);
            } else {
                printf("Sudah ada user yang bernama \"%s\". Silahkan coba lagi!\n\n", WordToStr(currentWord));
            }
        } else if (WordCompare(toKata("LOGIN"), toUpper(currentWord))) {
            printf("Masukkan username user WayangWave : ");
            GetCommand();
            if (searchUser(User, currentWord) != -1) {
                int UserID = searchUser(User, currentWord);
                printf("Berhasil masuk. Selamat datang, %s!\n\n", WordToStr(currentWord));
                *wayangwaveStarted = true;
                *currentUser = CreateObject(UserID, currentWord);
            } else {
                printf("Tidak ada user dengan username \"%s\". Silahkan coba lagi!\n\n", WordToStr(currentWord));
            }
        } else if (WordCompare(toKata("QUIT"), toUpper(currentWord))) {
            *quitAfterLoaded = true;
            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
        } else if (WordCompare(toKata("HELP"), toUpper(currentWord))) {
            help(1);
        } else {
            printf("Command tidak bisa dieksekusi!\n\n");
        }
    }
}

int main() {
    TabKata Penyanyi;
    Map Album;
    Map Lagu;

    boolean wayangwaveStarted = false;
    boolean configLoaded = false;
    boolean quitAfterLoaded = false;

    MakeEmpty(&Penyanyi);
    MapCreateEmpty(&Album);
    MapCreateEmpty(&Lagu);

    UserStorage User;
    initiateUserStorage(&User);
    Object currentUser;
    
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

    while (!configLoaded) {
        do {
            printf(">> ENTER COMMAND: ");
            GetCommand();

            if (WordCompare(toKata("HELP"), toUpper(currentWord))) {
                help(0);
            } else if (!WordCompare(toKata("START"), toUpper(currentWord)) && !WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0)))) {
                printf("Command tidak bisa dieksekusi!\n\n");
            }
        } while (!WordCompare(toKata("START"), toUpper(currentWord)) && !WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0))) && !WordCompare(toKata("HELP"), toUpper(currentWord)));
        
        if (WordCompare(toKata("START"), toUpper(currentWord))) {
            start(toKata("config.txt"), &Penyanyi, &Album, &Lagu, &User, &currentUser, false, &configLoaded);
        } else if (WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0)))) {
            start(AccessCommand(currentWord, 1), &Penyanyi, &Album, &Lagu, &User, &currentUser, true, &configLoaded);
        }
    }
    while (!quitAfterLoaded) {
        if (wayangwaveStarted) {
            menu(&Penyanyi, &((User).storage[currentUser.ID - 1].Antrian), &((User).storage[currentUser.ID - 1].Riwayat), &Album, &Lagu, &((User).storage[currentUser.ID - 1].PlaylistTitle), &((User).storage[currentUser.ID - 1].PlaylistData), &((User).storage[currentUser.ID - 1].Playing), &wayangwaveStarted, &quitAfterLoaded, &User, currentUser.ID);
        } else {
            userManagement(&User, &currentUser, &wayangwaveStarted, &quitAfterLoaded);
        }
    }
    return 0;
}
