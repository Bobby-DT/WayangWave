#include <stdio.h>
#include "playlist.h"

void playlist() {
    GetCommand();
    if (WordCompare(toKata("CREATE"), AccessCommand(currentWord, 1))) {
        printf("Masukkan nama playlist yang ingin dibuat : ");
        boolean valid = false;
        do {
            // cek apakah nama playlist setidaknya memiliki 3 karakter selain whitespace
            GetCommand();
            
            if (valid) {
                // buat playlist
                printf("Playlist ");
                TulisWord(currentWord);
                printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
            } else {
                printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            }
        } while (!valid);
    } else if (WordCompare(toKata("ADD"), AccessCommand(currentWord, 1))) {
        if (WordCompare(toKata("SONG"), AccessCommand(currentWord, 2))) {
            
        } else if (WordCompare(toKata("ALBUM"), AccessCommand(currentWord, 2))) {
            
        }
    } else if (WordCompare(toKata("SWAP"), AccessCommand(currentWord, 1))) {
        
    } else if (WordCompare(toKata("REMOVE"), AccessCommand(currentWord, 1))) {
        
    } else if (WordCompare(toKata("DELETE"), AccessCommand(currentWord, 1))) {
        
    }
}