#include <stdio.h>
#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../Lagu/song.h"
#include "listlinier.h"
#include "../List/array.h"
#include "../List/arraydinword.h"
#include "../List/arraydin.h"
#include "../SetMap/set.h"
#include "../SetMap/map.h"
#include "../Lagu/lagu.h"

int main() {
    TabKata Penyanyi;
    Map Album;
    Map Lagu;
    MakeEmpty(&Penyanyi);
    MapCreateEmpty(&Album);
    MapCreateEmpty(&Lagu);
    
    ArrayDinWord PlaylistTitle;
    ArrayDin PlaylistData;
    PlaylistTitle = MakeArrayDinWord();
    PlaylistData = MakeArrayDin();

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
    printf("Inserting PlaylistTitle & PlaylistData . . . \n\n");
    int jumlahPlaylist = 2;
    for (int i = 0; i < jumlahPlaylist; i++) {
        int jumlahLaguPlaylist = 2;
        printf("Declaring ListLinier . . .\nListLinier newPlaylist;\n\n");
        ListLinier newPlaylist;
        printf("Creating Empty ListLinier . . .\nCreateEmptyListLinier(&newPlaylist);\n\n");
        CreateEmptyListLinier(&newPlaylist);
        Word namaPlaylist = toKata("Playlist");
        concatWord(&namaPlaylist, intToWord(i+1));
        InsertLastArrayDinWord(&PlaylistTitle, namaPlaylist);
        InsertLastArrayDin(&PlaylistData, newPlaylist);
        int PlaylistID = (PlaylistData).Neff;
        for (int k = 0; k < jumlahLaguPlaylist; k++) {
            printf("Creating New Song . . .\nSong newLaguPlaylist = CreateLagu(1, PlaylistID, k+1, PlaylistID);\n");
            Song newLaguPlaylist = CreateLagu(1, PlaylistID, k+1, PlaylistID);
            printf("Inserting New Song . . .\nInsVLastListLinier(&((PlaylistData).A[PlaylistID - 1]), newLaguPlaylist);\n");
            InsVLastListLinier(&((PlaylistData).A[PlaylistID - 1]), newLaguPlaylist);
        }
        printf("\n");
    }

    printf("PrintArrayDinWord(PlaylistTitle):\n");
    PrintArrayDinWord(PlaylistTitle);
    printf("\n");

    printf("IsEmptyListLinier(GetArrayDin(PlaylistData, 0)): %d\n", IsEmptyListLinier(GetArrayDin(PlaylistData, 0)));
    printf("IsEmptyListLinier(GetArrayDin(PlaylistData, 1)): %d\n\n", IsEmptyListLinier(GetArrayDin(PlaylistData, 1)));

    printf("NumberElmtListLinier(GetArrayDin(PlaylistData, 0)): %d\n", NumberElmtListLinier(GetArrayDin(PlaylistData, 0)));
    printf("NumberElmtListLinier(GetArrayDin(PlaylistData, 1)): %d\n\n", NumberElmtListLinier(GetArrayDin(PlaylistData, 1)));

    printf("PrintInfoListLinier(GetArrayDin(PlaylistData, 0)):\n");
    PrintInfoListLinier(GetArrayDin(PlaylistData, 0));
    printf("\n");
    printf("PrintInfoListLinier(GetArrayDin(PlaylistData, 1)):\n");
    PrintInfoListLinier(GetArrayDin(PlaylistData, 1));
    printf("\n");

    return 0;
}