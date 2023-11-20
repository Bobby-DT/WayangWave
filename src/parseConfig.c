#include "parseConfig.h"

void GetIDfromConfig(TabKata *Penyanyi, Map *Album, Map *Lagu, int PlaylistID, Word failedAlert, Song *Result) {
    int PenyanyiID = GetPenyanyiID(&Penyanyi, AccessConfig2(currentWord, 0));
    int AlbumID = GetAlbumID(&Album, AccessConfig2(currentWord, 1), PenyanyiID);
    int LaguID = GetLaguID(&Lagu, AccessConfig2(currentWord, 2), AlbumID);
    if (PenyanyiID == -1 || AlbumID == -1 || LaguID == -1) {
        PrintWord(failedAlert);
        printf("\n");
    } else {
        (*Result).PenyanyiID = PenyanyiID;
        (*Result).AlbumID = AlbumID;
        (*Result).LaguID = LaguID;
        (*Result).PlaylistID = PlaylistID;
    }
}

void parseConfig(Word filesrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    char dir[50] = "./save/";
    for (int i = 0; i < filesrc.Length; i++) {
        dir[7 + i] = filesrc.TabWord[i];
    }
    dir[7 + filesrc.Length] = '\0';
    FILE* input = fopen(dir, "r");

    if (input == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n\n");
    } else {
        STARTWORD(input);
        int jumlahTotalAlbum = 0;
        int jumlahPenyanyi = WordToInt(currentWord);
        for (int j = 0; j < jumlahPenyanyi; j++) {
            ADVWORD();
            int jumlahAlbum = WordToInt(AccessCommand(currentWord, 0));
            Word namaPenyanyi = AccessConfig(currentWord, 1);
            Set AlbumofPenyanyi;
            SetCreateEmpty(&AlbumofPenyanyi);
            for (int k = 0; k < jumlahAlbum; k++) {
                ADVWORD();
                int jumlahLagu = WordToInt(AccessCommand(currentWord, 0));
                Word namaAlbum = AccessConfig(currentWord, 1);
                // Insert Album
                Object newAlbum = CreateObject(jumlahTotalAlbum+1, namaAlbum);
                SetAdd(&AlbumofPenyanyi, newAlbum);
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
            SetEl(&Penyanyi, j, namaPenyanyi);
            MapInsert(&Album, namaPenyanyi, AlbumofPenyanyi);
        }
        ADVWORD();
        if (currentChar != ' ') {
            // Insert Curently Playing Song
            GetIDfromConfig(&Penyanyi, &Album, &Lagu, -1, toKata("Gagal memuat lagu yang sedang dimainkan dari save file!"), &Playing);
            
            // Insert saved queue
            ADVWORD();
            int jumlahQueue = WordToInt(currentWord);
            for (int j = 0; j < jumlahQueue; j++) {
                ADVWORD();
                Song newLaguQueue;
                CreateEmptyLagu(&newLaguQueue);
                GetIDfromConfig(&Penyanyi, &Album, &Lagu, -1, toKata("Gagal memuat lagu yang tersimpan di playlist dari save file!"), &newLaguQueue);
                enqueue(&Antrian, newLaguQueue);
            }
            // Insert saved history
            ADVWORD();
            int jumlahAntrian = WordToInt(currentWord);
            Stack RiwayatConfig;
            CreateEmptyStack(&RiwayatConfig);
            for (int j = 0; j < jumlahAntrian; j++) {
                ADVWORD();
                Song newLaguAntrian;
                CreateEmptyLagu(&newLaguAntrian);
                GetIDfromConfig(&Penyanyi, &Album, &Lagu, -1, toKata("Gagal memuat lagu yang tersimpan di playlist dari save file!"), &newLaguAntrian);
                PushStack(&RiwayatConfig, newLaguAntrian);
            }
            InvesrseStack(&RiwayatConfig, &Antrian);
            // Insert saved playlist
            ADVWORD();
            int jumlahPlaylist = WordToInt(currentWord);
            for (int j = 0; j < jumlahPlaylist; j++) {
                ADVWORD();
                int jumlahLaguPlaylist = WordToInt(AccessCommand(currentWord, 0));
                List newPlaylist;
                CreateEmptyList(&newPlaylist);
                InsertLastArrayDinWord(&PlaylistTitle, AccessConfig(currentWord, 1));
                InsertLastArrayDin(&PlaylistData, newPlaylist);
                int PlaylistID = (*PlaylistData).Neff - 1;
                for (int k = 0; k < jumlahLaguPlaylist; k++) {
                    ADVWORD();
                    Song newLaguPlaylist;
                    CreateEmptyLagu(&newLaguPlaylist);
                    GetIDfromConfig(&Penyanyi, &Album, &Lagu, PlaylistID, toKata("Gagal memuat lagu yang tersimpan di playlist dari save file!"), &newLaguPlaylist);
                    InsVLastListLinier((*PlaylistData).[PlaylistID - 1], newLaguPlaylist);
                }
            }
        }
    }
    fclose(input);
}