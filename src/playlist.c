#include <stdio.h>
#include "playlist.h"

void playlist(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *MapPenyanyi, Map *Album, MapPlaylist *Playlist) {
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
                    InsertPlaylist(*Playlist, currentWord, newPlaylist);
                    printf("Playlist ");
                    TulisWord(currentWord);
                    printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
                } else {
                    printf("Sudah ada Playlist dengan nama tersebut! Silakan coba lagi.\n");
                }
            } else {
                printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            }
        } while (!(nama_playlist_len >= 3) || IsMemberPlaylist(&Playlist, currentWord));
    } else if (WordCompare(toKata("ADD"), AccessCommand(currentWord, 1))) {
        boolean addSong = false;
        Word penyanyi;
        Word album;

        if (WordCompare(toKata("SONG"), AccessCommand(currentWord, 2))) {
            addSong = true;
            Word lagu;
        } else if (WordCompare(toKata("ALBUM"), AccessCommand(currentWord, 2))) {
            
        } else {

        }

        printf("Daftar Penyanyi :\n");
        // print daftar penyanyi
        do {
            printf("Masukkan Nama Penyanyi yang dipilih : ");
            GetCommand();
            if (!IsMember(&Penyanyi, currentWord)) {
                printf("Penyanyi ");
                TulisWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!IsMember(&Penyanyi, currentWord))
        // Pengoperasian input penyanyi

        printf("Daftar Album oleh ");
        TulisWord(currentWord);
        printf(" :\n");
        // print daftar album
        do {
            printf("Masukkan Judul Album yang dipilih : ");
            GetCommand();
            if (!/*isMemberMap*/(&Album, currentWord)) {
                printf("Album ");
                TulisWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!/*isMemberMap*/(&Album, currentWord))
        // Pengoperasian input penyanyi

        if (addSong) {
            printf("Daftar Lagu Album ");
            TulisWord(album);
            printf(" oleh ");
            TulisWord(penyanyi);
            printf(" :\n");
            // print daftar lagu
            do {
                printf("Masukkan ID Lagu yang dipilih : ");
                GetCommand();
                if () {
                    printf("Album ");
                    TulisWord(currentWord);
                    printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
                }
            } while (!/*isMemberMap*/(&Album, currentWord))
            // Pengoperasian input penyanyi
        }

    } else if (WordCompare(toKata("SWAP"), AccessCommand(currentWord, 1))) {
        int playlistID = /*int(AccessCommand(currentWord, 2)) + 1*/;
        boolean invalidPlaylistID = playlistID > (*Playlist).Count || playlistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmt((*Playlist).Elements[playlistID - 1].Value);
            int playlistX = /*int(AccessCommand(currentWord, 3))*/;
            int playlistY = /*int(AccessCommand(currentWord, 4))*/;
            if (playlistX > jumlahLaguPlaylist || playlistX < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist “", playlistX);
                TulisWord((*Playlist).Elements[playlistID - 1].Key);
                printf("”\n");
            } else {
                if (playlistY > jumlahLaguPlaylist || playlistY < 1) {
                    printf("Tidak ada lagu dengan urutan %d di playlist “", playlistY);
                    TulisWord((*Playlist).Elements[playlistID - 1].Key);
                    printf("”\n");
                } else {
                    // swap playlist

                    if (/*swap berhasil*/) {
                        printf("Berhasil menukar lagu dengan nama “");
                        TulisWord(/**/);
                        printf("” dengan “");
                        TulisWord(/**/);
                        printf("” di playlist “");
                        TulisWord((*Playlist).Elements[playlistID - 1].Key);
                        printf("”\n");
                    }
                }
            }
        } else {
            print("Tidak ada playlist dengan ID ");
            TulisWord(AccessCommand(currentWord, 2));
            printf(".\n");
        }
    } else if (WordCompare(toKata("REMOVE"), AccessCommand(currentWord, 1))) {
        int playlistID = /*int(AccessCommand(currentWord, 2)) + 1*/;
        boolean invalidPlaylistID = playlistID > (*Playlist).Count || playlistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmt((*Playlist).Elements[playlistID - 1].Value);
            int laguN = /*int(AccessCommand(currentWord, 3))*/;
            if (laguN > jumlahLaguPlaylist || laguN < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist “", laguN);
                TulisWord((*Playlist).Elements[playlistID - 1].Key);
                printf("”\n");
            } else {
                // remove lagu di playlist

                if (/*berhasil*/) {
                    printf("Lagu “");
                    TulisWord(/*lagu*/);
                    printf("” oleh “");
                    TulisWord(/*penyanyi*/);
                    printf("” telah dihapus dari playlist “");
                    TulisWord((*Playlist).Elements[playlistID - 1].Key);
                    printf("”!");
                }
            }
        } else {
            printf("Tidak ada playlist dengan ID %d.\n", playlistID);
        }
    } else if (WordCompare(toKata("DELETE"), AccessCommand(currentWord, 1))) {
        // print list playlist

        do {
            printf("Masukkan ID Playlist yang dipilih : ");
            GetCommand();
            int playlistID = /*int(currentWord) + 1*/;
            boolean invalidPlaylistID = playlistID > (*Playlist).Count || playlistID < 1;
            if (invalidPlaylistID) {
                printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", playlistID);
            }
        } while (invalidPlaylistID);
        int jumlahPlaylistSebelumnya = (*Playlist).Count;
        DeletePlaylistByID(*Playlist, /*int(currentWord)*/)
        if ((*Playlist).Count == jumlahPlaylistSebelumnya - 1) {
            printf("Playlist ID %d dengan judul ");
            TulisWord(currentWord);
            printf(" berhasil dihapus.\n");
        }
    }
}