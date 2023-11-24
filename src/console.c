#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void menu(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing, boolean *wayangwaveStarted, boolean *quitAfterLoaded, UserStorage *User, int UserID) {
    printf(">> ENTER COMMAND: ");
    GetCommand();

    if (WordCompare(toKata("START"), toUpper(currentWord)) || WordCompare(toKata("LOAD"), toUpper(AccessCommand(currentWord, 0)))) {
        printf("WayangWave sudah dijalankan. Command tidak bisa dieksekusi! Masukkan command HELP untuk bantuan\n\n");
    } else if (WordCompare(toKata("LIST"), toUpper(AccessCommand(currentWord, 0)))) {
        if (WordCompare(toKata("DEFAULT"), toUpper(AccessCommand(currentWord, 1)))) {
            ListDefault(Penyanyi, Album, Lagu);
        } else if (WordCompare(toKata("PLAYLIST"), toUpper(AccessCommand(currentWord, 1)))) {
            ListPlaylist(PlaylistTitle);
            if ((*PlaylistTitle).Neff > 0) {
                isiPlaylist(Penyanyi, Album, Lagu, PlaylistTitle, PlaylistData);
            }
        } else {
            printf("Command tidak diketahui!\n\n");
        }
    } else if (WordCompare(toKata("PLAY"), toUpper(AccessCommand(currentWord, 0)))) {
        play(Penyanyi, Antrian, Riwayat, Album, Lagu, PlaylistTitle, PlaylistData, Playing);
    } else if (WordCompare(toKata("QUEUE"), toUpper(AccessCommand(currentWord, 0)))) {
        if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 1)))) {
            QueueSong(Penyanyi, Antrian, Album, Lagu);
        } else if (WordCompare(toKata("PLAYLIST"), toUpper(AccessCommand(currentWord, 1)))) {
            QueuePlaylist(Antrian, Lagu, PlaylistTitle, PlaylistData);
        } else if (WordCompare(toKata("SWAP"), toUpper(AccessCommand(currentWord, 1)))) {
            QueueSwap(Antrian, AccessCommand(currentWord, 2), AccessCommand(currentWord, 3), Lagu);
        } else if (WordCompare(toKata("REMOVE"), toUpper(AccessCommand(currentWord, 1)))) {
            QueueRemove(Penyanyi, Antrian, Album, Lagu, AccessCommand(currentWord, 2));
        } else if (WordCompare(toKata("CLEAR"), toUpper(AccessCommand(currentWord, 1)))) {
            QueueClear(Antrian);
        } else {
            printf("Command tidak diketahui!\n\n");
        }
    } else if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 0)))) {
        if (WordCompare(toKata("NEXT"), toUpper(AccessCommand(currentWord, 1)))) {
            SongNext(Penyanyi, Antrian, Riwayat, Lagu, Playing);
        } else if (WordCompare(toKata("PREVIOUS"), toUpper(AccessCommand(currentWord, 1)))) {
            SongPrevious(Penyanyi, Antrian, Riwayat, Lagu, Playing);
        } else {
            printf("Command tidak diketahui!\n\n");
        }
    } else if (WordCompare(toKata("PLAYLIST"), toUpper(AccessCommand(currentWord, 0)))) {
        playlist(Penyanyi, Antrian, Riwayat, Album, Lagu, PlaylistTitle, PlaylistData);
    } else if (WordCompare(toKata("ENHANCE"), toUpper(currentWord))) {
        enhance(Penyanyi, Riwayat, Album, Lagu, PlaylistTitle, PlaylistData);
    } else if (WordCompare(toKata("STATUS"), toUpper(currentWord))) {
        status(Penyanyi, Antrian, Album, Lagu, PlaylistTitle, Playing);
        /*
        printf("Riwayat: ");
        Song riwayat = InfoTop(*Riwayat);
        PrintSong(Penyanyi, Album, Lagu, riwayat.PenyanyiID, riwayat.AlbumID, riwayat.LaguID);
        printf("\n\n");
        */
    } else if (WordCompare(toKata("SAVE"), toUpper(AccessCommand(currentWord, 0)))) {
        save(AccessCommand(currentWord, 1), Penyanyi, Album, Lagu, User, UserID);
    } else if (WordCompare(toKata("QUIT"), toUpper(currentWord))) {
        quit(Penyanyi, Album, Lagu, User, UserID);
        *quitAfterLoaded = true;
    } else if (WordCompare(toKata("HELP"), toUpper(currentWord))) {
        help(2);
    } else if (WordCompare(toKata("LOGOUT"), toUpper(currentWord))) {
        *wayangwaveStarted = false;
        printf("Berhasil keluar. Login kembali untuk menjalankan WayangWave.\n\n");
    } else {
        printf("Command tidak diketahui!\n\n");
    }
}