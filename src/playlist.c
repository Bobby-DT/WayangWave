#include <stdio.h>
#include "playlist.h"

void playlist(MapPlaylist *Playlist) {
    GetCommand();
    if (WordCompare(toKata("CREATE"), AccessCommand(currentWord, 1))) {
        printf("Masukkan nama playlist yang ingin dibuat : ");
        do {
            GetCommand();
            int nama_playlist_len = 0;
            for (int i = 0; i < currentWord.Length; i++) {
                if (currentWord.TabWord[i] != ' ') nama_playlist_len++;
            }
            if (nama_playlist_len >= 3) {
                if (!IsMemberPlaylist(&Playlist, currentWord)) {
                    List newPlaylist;
                    CreateEmptyList(&newPlaylist);
                    InsertPlaylist(*Playlist, currentWord, newPlaylist)
                    printf("Playlist ");
                    TulisWord(currentWord);
                    printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
                } else {
                    printf("Sudah ada Playlist dengan nama tersebut! Gunakan nama yang lain!\n");
                }
            } else {
                printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            }
        } while (!(nama_playlist_len >= 3) || IsMemberPlaylist(&Playlist, currentWord));
    } else if (WordCompare(toKata("ADD"), AccessCommand(currentWord, 1))) {
        if (WordCompare(toKata("SONG"), AccessCommand(currentWord, 2))) {
            
        } else if (WordCompare(toKata("ALBUM"), AccessCommand(currentWord, 2))) {
            
        }
    } else if (WordCompare(toKata("SWAP"), AccessCommand(currentWord, 1))) {
        
    } else if (WordCompare(toKata("REMOVE"), AccessCommand(currentWord, 1))) {
        
    } else if (WordCompare(toKata("DELETE"), AccessCommand(currentWord, 1))) {
        
    }
}