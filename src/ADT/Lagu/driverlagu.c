#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "song.h"
#include "../List/array.h"
#include "../List/arraydinword.h"
#include "../SetMap/set.h"
#include "../SetMap/map.h"
#include "lagu.h"

int main() {
    TabKata Penyanyi;
    Map Album;
    Map Lagu;
    ArrayDinWord PlaylistTitle;
    MakeEmpty(&Penyanyi);
    MapCreateEmpty(&Album);
    MapCreateEmpty(&Lagu);
    PlaylistTitle = MakeArrayDinWord();

    int jumlahTotalAlbum = 0;
    int jumlahPenyanyi = 2;
    for (int j = 0; j < jumlahPenyanyi; j++) {
        int jumlahAlbum = 2;
        Word namaPenyanyi = toKata("Penyanyi");
        concatWord(&namaPenyanyi, intToWord(j+1));
        Set AlbumofPenyanyi;
        SetCreateEmpty(&AlbumofPenyanyi);
        for (int k = 0; k < jumlahAlbum; k++) {
            int jumlahLagu = 2;
            Word namaAlbum = toKata("Album");
            concatWord(&namaAlbum, intToWord(k+1));
            concatWord(&namaAlbum, toKata("Penyanyi"));
            concatWord(&namaAlbum, intToWord(j+1));
            // Insert Album
            Object newAlbum = CreateObject(jumlahTotalAlbum+1, namaAlbum);
            SetAdd(&AlbumofPenyanyi, newAlbum);
            jumlahTotalAlbum++;

            Set LaguofAlbum;
            SetCreateEmpty(&LaguofAlbum);
            for (int l = 0; l < jumlahLagu; l++) {
                Word namaLagu = toKata("Lagu");
                concatWord(&namaLagu, intToWord(l+1));
                concatWord(&namaLagu, toKata("Album"));
                concatWord(&namaLagu, intToWord(k+1));
                concatWord(&namaLagu, toKata("Penyanyi"));
                concatWord(&namaLagu, intToWord(j+1));
                Object newLagu = CreateObject(l+1, namaLagu);
                SetAdd(&LaguofAlbum, newLagu);
            }
            MapInsert(&Lagu, namaAlbum, LaguofAlbum);
        }
        SetEl(&Penyanyi, j, namaPenyanyi);
        MapInsert(&Album, namaPenyanyi, AlbumofPenyanyi);
    }
    int jumlahPlaylist = 2;
    for (int i = 0; i < jumlahPlaylist; i++) {
        Word namaPlaylist = toKata("Playlist");
        concatWord(&namaPlaylist, intToWord(i+1));
        InsertLastArrayDinWord(&PlaylistTitle, namaPlaylist);
    }
    printf("Testing Get Penyanyi, Album, Lagu, & Playlist functions . . .\n\n");
    
    printf("GetPenyanyi(&Penyanyi, 1): ");
    PrintWord(GetPenyanyi(&Penyanyi, 1));
    printf("\n");
    printf("GetPenyanyi(&Penyanyi, 2): ");
    PrintWord(GetPenyanyi(&Penyanyi, 2));
    printf("\n\n");

    printf("GetAlbum(&Lagu, 1): ");
    PrintWord(GetAlbum(&Lagu, 1));
    printf("\n");
    printf("GetAlbum(&Lagu, 2): ");
    PrintWord(GetAlbum(&Lagu, 2));
    printf("\n");
    printf("GetAlbum(&Lagu, 3): ");
    PrintWord(GetAlbum(&Lagu, 3));
    printf("\n");
    printf("GetAlbum(&Lagu, 4): ");
    PrintWord(GetAlbum(&Lagu, 4));
    printf("\n\n");

    printf("GetLagu(&Lagu, 1, 2): ");
    PrintWord(GetLagu(&Lagu, 1, 2));
    printf("\n");
    printf("GetLagu(&Lagu, 4, 1): ");
    PrintWord(GetLagu(&Lagu, 4, 1));
    printf("\n\n");

    printf("GetPlaylist(&PlaylistTitle, 1): ");
    PrintWord(GetPlaylist(&PlaylistTitle, 1));
    printf("\n");
    printf("GetPlaylist(&PlaylistTitle, 2): ");
    PrintWord(GetPlaylist(&PlaylistTitle, 2));
    printf("\n\n");

    printf("GetPenyanyiID(&Penyanyi, toKata('Penyanyi 2')): %d\n", GetPenyanyiID(&Penyanyi, toKata("Penyanyi 2")));
    printf("GetAlbumID(&Album, toKata('Album 1 Penyanyi 2'), 2): %d\n", GetAlbumID(&Album, toKata("Album 1 Penyanyi 2"), 2));
    printf("GetLaguID(&Lagu, toKata('Lagu 1 Album 2 Penyanyi 1'), 2): %d\n", GetLaguID(&Lagu, toKata("Lagu 1 Album 2 Penyanyi 1"), 2));
    printf("GetPlaylistID(&PlaylistTitle, toKata('Playlist 2')): %d\n\n", GetPlaylistID(&PlaylistTitle, toKata("Playlist 2")));

    printf("PrintSong(&Penyanyi, &Album, &Lagu, 2, 3, 2): \n");
    PrintSong(&Penyanyi, &Album, &Lagu, 2, 3, 2);
    printf("\n");

    return 0;
}
