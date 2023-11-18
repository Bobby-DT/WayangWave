#include "parseConfig.h"

void parseConfig(char * filesrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    char dir[50] = "./save/";
    int i = 0;
    while (filesrc[i]) {
        dir[7 + i] = filesrc[i];
        i++;
    }
    dir[7 + i] = '\0';
    FILE* input = fopen(dir, "r");

    if (input == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n\n");
    } else {
        STARTWORD(input);
        int jumlahTotalAlbum = 0;
        int jumlahPenyayi = WordToInt(currentWord);
        for (int j = 0; j < jumlahPenyayi; j++) {
            ADVWORD();
            int jumlahAlbum = WordToInt(AccessCommand(currentWord, 0));
            Word namaPenyanyi = AccessCommand(currentWord, 1);
            Set AlbumofPenyayi;
            SetCreateEmpty(&AlbumofPenyayi);
            for (int k = 0; k < jumlahAlbum; k++) {
                ADVWORD();
                int jumlahLagu = WordToInt(AccessCommand(currentWord, 0));
                Word namaAlbum = AccessCommand(currentWord, 1);
                // Insert Album
                Object newAlbum = CreateObject(jumlahTotalAlbum+1, namaAlbum);
                SetAdd(&AlbumofPenyayi, newAlbum);
                jumlahTotalAlbum++;

                Set LaguofAlbum;
                SetCreateEmpty(&LaguofAlbum);
                for (int l = 0; l < jumlahLagu; l++) {
                    ADVWORD();
                    Object newLagu = CreateObject(l+1, currentWord);
                    SetAdd(&LaguofAlbum, newLagu);
                }
                MapInsert(&Lagu, namaAlbum, LaguofAlbum);
            }
            SetEl(Penyanyi, j, namaPenyanyi);
            MapInsert(&Album, namaPenyanyi, AlbumofPenyayi);
        }
    }
    ADVWORD();
    if (currentChar != ' ') {
        // Insert Curently Playing Song
        int PenyanyiID = GetPenyanyiID(&Penyanyi, AccessConfig(currentWord, 0));
        int AlbumID = GetAlbumID(&Album, AccessConfig(currentWord, 1), PenyanyiID);
        int LaguID = GetLaguID(&Lagu, AccessConfig(currentWord, 2), AlbumID);
        if (PenyanyiID == -1 || AlbumID == -1 || LaguID == -1) {
            printf("Gagal memuat lagu yang sedang dimainkan dari save file!\n\n");
        } else {
            (*Playing).PenyanyiID = PenyanyiID;
            (*Playing).AlbumID = AlbumID;
            (*Playing).LaguID = LaguID;
            (*Playing).PlaylistID = -1;
        }
    }
    fclose(input);
}