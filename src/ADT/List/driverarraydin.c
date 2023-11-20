#include <stdio.h>
#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../Lagu/song.h"
#include "../List Berkait/listlinier.h"
#include "../List/array.h"
#include "arraydinword.h"
#include "arraydin.h"
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
    
    printf("Declaring ArrayDinWord & ArrayDin . . .\nArrayDinWord PlaylistTitle;\nArrayDin PlaylistData;\n\n");
    ArrayDinWord PlaylistTitle;
    ArrayDin PlaylistData;
    printf("Creating Empty ArrayDinWord & ArrayDin . . .\nPlaylistTitle = MakeArrayDinWord();\nPlaylistData = MakeArrayDin();\n\n");
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
        ListLinier newPlaylist;
        CreateEmptyListLinier(&newPlaylist);
        Word namaPlaylist = toKata("Playlist");
        concatWord(&namaPlaylist, intToWord(i+1));
        InsertLastArrayDinWord(&PlaylistTitle, namaPlaylist);
        InsertLastArrayDin(&PlaylistData, newPlaylist);
        int PlaylistID = (PlaylistData).Neff;
        for (int k = 0; k < jumlahLaguPlaylist; k++) {
            Song newLaguPlaylist = CreateLagu(1, PlaylistID, k+1, PlaylistID);
            InsVLastListLinier(&((PlaylistData).A[PlaylistID - 1]), newLaguPlaylist);
        }
    }

    printf("PrintArrayDinWord(PlaylistTitle):\n");
    PrintArrayDinWord(PlaylistTitle);

    printf("IsEmptyArrayDinWord(PlaylistTitle): %d\n", IsEmptyArrayDinWord(PlaylistTitle));
    printf("IsEmptyArrayDin(PlaylistData): %d\n\n", IsEmptyArrayDin(PlaylistData));

    printf("LengthArrayDinWord(PlaylistTitle): %d\n", LengthArrayDinWord(PlaylistTitle));
    printf("LengthArrayDin(PlaylistData): %d\n\n", LengthArrayDin(PlaylistData));

    printf("GetArrayDinWord(PlaylistTitle, 1): ");
    PrintWord(GetArrayDinWord(PlaylistTitle, 1));
    printf("\n");
    printf("GetArrayDin(PlaylistData, 1): \n");
    printf("Info(First(GetArrayDin(PlaylistData, 1))).PenyanyiID\t: %d\n", Info(First(GetArrayDin(PlaylistData, 1))).PenyanyiID);
    printf("Info(First(GetArrayDin(PlaylistData, 1))).AlbumID\t: %d\n", Info(First(GetArrayDin(PlaylistData, 1))).AlbumID);
    printf("Info(First(GetArrayDin(PlaylistData, 1))).LaguID\t: %d\n", Info(First(GetArrayDin(PlaylistData, 1))).LaguID);
    printf("Info(First(GetArrayDin(PlaylistData, 1))).PlaylistID\t: %d\n\n", Info(First(GetArrayDin(PlaylistData, 1))).PlaylistID);

    printf("GetCapacityArrayDinWord(PlaylistTitle): %d\n", GetCapacityArrayDinWord(PlaylistTitle));
    printf("GetCapacityArrayDin(PlaylistData): %d\n\n", GetCapacityArrayDinWord(PlaylistTitle));
    
    printf("GetCapacityArrayDinWord(PlaylistTitle): %d\n", GetCapacityArrayDinWord(PlaylistTitle));
    printf("GetCapacityArrayDin(PlaylistData): %d\n", GetCapacityArrayDinWord(PlaylistTitle));
    
    return 0;
}