#include "parseConfig.h"

void GetIDfromConfig(TabKata *Penyanyi, Map *Album, Map *Lagu, int PlaylistID, Word failedAlert, Song *Result) {
    int PenyanyiID = GetPenyanyiID(Penyanyi, AccessConfig2(currentWord, 0));
    int AlbumID = GetAlbumID(Album, AccessConfig2(currentWord, 1), PenyanyiID);
    int LaguID = GetLaguID(Lagu, AccessConfig2(currentWord, 2), AlbumID);
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

void parseConfig(Word filesrc, TabKata *Penyanyi, Map *Album, Map *Lagu, UserStorage *User) {
    char dir[50] = "../save/";
    for (int i = 0; i < filesrc.Length; i++) {
        dir[8 + i] = filesrc.TabWord[i];
    }
    dir[8 + filesrc.Length] = '\0';
    //printf("%s\n", dir);
    FILE* input = fopen(dir, "r");

    if (input == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n\n");
    } else {
        currentWord.Length = 0;
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
                MapInsert(Lagu, namaAlbum, LaguofAlbum);
            }
            SetEl(Penyanyi, j, namaPenyanyi);
            MapInsert(Album, namaPenyanyi, AlbumofPenyanyi);
        }
        ADVWORD();
        //printf("currentChar: %c\n", currentChar);
        int UserID, jumlahUser, jumlahAntrian, jumlahRiwayat, jumlahPlaylist;
        if (currentChar != ' ') {
            jumlahUser = WordToInt(currentWord);
            //printf("jumlahUser: %d\n", jumlahUser);
            for (int i = 0; i < jumlahUser; i++) {
                ADVWORD();
                //printf("Nama User: %s\n", WordToStr(currentWord));
                UserID = createNewUser(User, currentWord);
                //printf("UserID: %d\n", UserID);
            }
            for (int i = 0; i < jumlahUser; i++) {
                UserID = i+1;
                ADVWORD();
                if (currentChar != ' ') {
                    // Insert Curently Playing Song
                    //printf("Curently Playing Song: %s\n", WordToStr(currentWord));
                    GetIDfromConfig(Penyanyi, Album, Lagu, -1, toKata("Gagal memuat lagu yang sedang dimainkan dari save file!"), &((User)->storage[UserID - 1].Playing));
                } 
                ADVWORD();
                if (currentChar != ' ') {
                    // Insert saved queue
                    jumlahAntrian = WordToInt(currentWord);
                    //printf("jumlahAntrian: %d\n", jumlahAntrian);
                    for (int j = 0; j < jumlahAntrian; j++) {
                        ADVWORD();
                        Song newLaguQueue;
                        CreateEmptyLagu(&newLaguQueue);
                        GetIDfromConfig(Penyanyi, Album, Lagu, -1, toKata("Gagal memuat lagu yang tersimpan di antrian dari save file!"), &newLaguQueue);
                        enqueue(&((User)->storage[UserID - 1].Antrian), newLaguQueue);
                    }
                }
                ADVWORD();
                if (currentChar != ' ') {
                    // Insert saved history
                    jumlahRiwayat = WordToInt(currentWord);
                    //printf("jumlahRiwayat: %d\n", jumlahRiwayat);
                    Stack RiwayatConfig;
                    CreateEmptyStack(&RiwayatConfig);
                    for (int j = 0; j < jumlahRiwayat; j++) {
                        ADVWORD();
                        Song newLaguAntrian;
                        CreateEmptyLagu(&newLaguAntrian);
                        GetIDfromConfig(Penyanyi, Album, Lagu, -1, toKata("Gagal memuat lagu yang tersimpan di riwayat dari save file!"), &newLaguAntrian);
                        PushStack(&RiwayatConfig, newLaguAntrian);
                    }
                    InvesrseStack(&RiwayatConfig, &((User)->storage[UserID - 1].Riwayat));
                }
                ADVWORD();
                if (currentChar != ' ') {
                    // Insert saved playlist
                    jumlahPlaylist = WordToInt(currentWord);
                    //printf("jumlahPlaylist: %d\n", jumlahPlaylist);
                    for (int j = 0; j < jumlahPlaylist; j++) {
                        ADVWORD();
                        //printf("Nama Playlist: %d\n", jumlahPlaylist);
                        int jumlahLaguPlaylist = WordToInt(AccessCommand(currentWord, 0));
                        ListLinier newPlaylist;
                        CreateEmptyListLinier(&newPlaylist);
                        InsertLastArrayDinWord(&((User)->storage[UserID - 1].PlaylistTitle), AccessConfig(currentWord, 1));
                        InsertLastArrayDin(&((User)->storage[UserID - 1].PlaylistData), newPlaylist);
                        int PlaylistID = (*User).storage[UserID - 1].PlaylistData.Neff;
                        for (int k = 0; k < jumlahLaguPlaylist; k++) {
                            ADVWORD();
                            //printf("Lagu Of Playlist: %d\n", jumlahPlaylist);
                            Song newLaguPlaylist;
                            CreateEmptyLagu(&newLaguPlaylist);
                            GetIDfromConfig(Penyanyi, Album, Lagu, PlaylistID, toKata("Gagal memuat lagu yang tersimpan di playlist dari save file!"), &newLaguPlaylist);
                            InsVLastListLinier(&((User)->storage[UserID - 1].PlaylistData.A[PlaylistID - 1]), newLaguPlaylist);
                        }
                    }
                }
            }
        }
        fclose(input);
    }
}