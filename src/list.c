#include "list.h"

void PrintDaftarPenyanyi(TabKata *Penyanyi) {
    printf("Daftar Penyanyi :");
    for (int i = 0; i < (*Penyanyi).Neff; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((*Penyanyi).TK[i]);
    }
    printf("\n\n");
}

void PrintDaftarAlbum(TabKata *Penyanyi, Map *Album, int PenyanyiID) {
    printf("\nDaftar Album oleh ");
    PrintWord(GetPenyanyi(Penyanyi, PenyanyiID));
    printf(" :");
    for (int i = 0; i < (*Album).Elements[PenyanyiID - 1].Value.length; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((*Album).Elements[PenyanyiID - 1].Value.buffer[i].Title);
    }
    printf("\n\n");
}

void PrintDaftarLagu(TabKata *Penyanyi, Map *Album, Map *Lagu, int PenyanyiID, int AlbumID) {
    printf("Daftar Lagu Album ");
    PrintWord(GetAlbum(Album, AlbumID));
    printf(" oleh ");
    PrintWord(GetPenyanyi(Penyanyi, PenyanyiID));
    printf(" :\n");
    int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;
    for (int i = 0; i < AlbumLength; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((*Lagu).Elements[AlbumID - 1].Value.buffer[i].Title);
    }
    printf("\n\n");
}

void ListDefault(TabKata *Penyanyi, Map *Album, Map *Lagu) {
    boolean continueAlbum = false;
    boolean continueLagu = false;
    int PenyanyiID;
    int AlbumID;
    
    PrintDaftarPenyanyi(Penyanyi);
    do {
        printf("Ingin melihat album yang ada?(Y/N): ");
        GetCommand();
        if (!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord))) {
            printf("Command tidak diketahui! Jawab dengan y/N!\n");
        }
    } while(!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord)));
    if (WordCompare(toKata("Y"), toUpper(currentWord))) {
        continueAlbum = true;
    }
    if (continueAlbum) {
        do {
            printf("Pilih penyanyi untuk melihat album mereka: ");
            GetCommand();
            if (!IsMember(*Penyanyi, currentWord)) {
                printf("\nPenyanyi ");
                PrintWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!IsMember(*Penyanyi, currentWord));
        PenyanyiID = searchList(*Penyanyi, currentWord) + 1;
        PrintDaftarAlbum(Penyanyi, Album, PenyanyiID);
        do {
            printf("Ingin melihat lagu yang ada?(Y/N): ");
            GetCommand();
            if (!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord))) {
                printf("Command tidak diketahui! Jawab dengan y/N!\n");
            }
        } while(!WordCompare(toKata("Y"), toUpper(currentWord)) && !WordCompare(toKata("N"), toUpper(currentWord)));
        if (WordCompare(toKata("Y"), toUpper(currentWord))) {
            continueLagu = true;
        }
    }
    if (continueLagu) {
        do {
            printf("Pilih album untuk melihat lagu yang ada di album : ");
            GetCommand();
            printf("searchMap(*Album, currentWord): %d\n", searchMap(*Album, currentWord));
            if (!MapIsMember(*Album, currentWord)) {
                printf("\nAlbum ");
                PrintWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!MapIsMember(*Album, currentWord));
        AlbumID = searchMap(*Album, currentWord) + 1;
        PrintDaftarLagu(Penyanyi, Album, Lagu, PenyanyiID, AlbumID);
    }
}

void ListPlaylist(ArrayDinWord *PlaylistTitle) {
    printf("Daftar Playlist Pengguna :\n");
    for (int i = 0; i < (*PlaylistTitle).Neff; i++) {
        printf("\n\t%d. ", i+1);
        PrintWord((*PlaylistTitle).A[i]);
    }
    printf("\n\n");
}