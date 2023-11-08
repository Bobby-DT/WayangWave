#include <stdio.h>
#include "playlist.h"

void playlist() {
    GetCommand();
    if (WordCompare(toKata("CREATE"), currentWord)) {
        printf("Masukkan nama playlist yang ingin dibuat : ");
        GetCommand();

        if (true) { // cek apakah nama playlist setidaknya memiliki 3 karakter selain whitespace
            printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", nama_playlist);
        } else {
            // buat playlist
            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
        }
    } else if (WordCompare(toKata("ADD"), currentWord)) {
        
    } else if (WordCompare(toKata("SWAP"), currentWord)) {
        
    } else if (WordCompare(toKata("REMOVE"), currentWord)) {
        
    } else if (WordCompare(toKata("DELETE"), currentWord)) {
        
    }
}