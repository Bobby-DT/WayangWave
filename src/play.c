#include "play.h"

void play(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 1)))) {
        PrintDaftarPenyayi(&Penyanyi);
        do {
            printf("Masukkan Nama Penyanyi yang dipilih : ");
            GetCommand();
            if (!IsMember(&Penyanyi, currentWord)) {
                printf("Penyanyi ");
                PrintWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!IsMember(&Penyanyi, currentWord));
        int PenyanyiID = searchList(&Penyanyi, currentWord) + 1;

        PrintDaftarAlbum(&Album, PenyanyiID);
        do {
            printf("Masukkan Judul Album yang dipilih : ");
            GetCommand();
            if (!MapIsMember(&Album, currentWord)) {
                printf("Album ");
                PrintWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!MapIsMember(&Album, currentWord));
        int AlbumID = searchMap(&Album, currentWord) + 1;

        PrintDaftarLagu(&Penyanyi, &Album, &Lagu, PenyanyiID, AlbumID);
        do {
            printf("Masukkan ID Lagu yang dipilih : ");
            GetCommand();
            if (WordToInt(currentWord) >= AlbumLength) {
                printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
            }
        } while (WordToInt(currentWord) >= AlbumLength);  
        int LaguID = WordToInt(currentWord);

        *Playing = CreateLagu(PenyanyiID, AlbumID, LaguID, -1);
        while (!queue_isEmpty(*Antrian)) {
            Song del;
            dequeue(&Antrian, &del);
        }
        while (!IsEmptyStack(*Riwayat)) {
            Song del;
            PopStack(&Riwayat, &del);
        }

        printf("Memutar lagu \"");
        PrintWord(GetLagu(&Lagu, AlbumID, LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(&Penyanyi, PenyanyiID));
        printf("\"\n\n");
    } else if (WordCompare(toKata("PLAYLIST"), toUpper(AccessCommand(currentWord, 1)))) {
        ListPlaylist(&PlaylistTitle);
        do {
            printf("Masukkan ID Playlist yang dipilih : ");
            GetCommand();
            if (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0) {
                printf("Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
            }
        } while (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0);
        int PlaylistID = WordToInt(currentWord);
        Word playlistTitle = (*PlaylistTitle).A[playlistID - 1];
        
        // Ambil informasi lagu dari playlist dengan ID tertentu
        address playlistSongs = First((*PlaylistData).Elements[playlistID - 1]);

        *Playing = Info(playlistSongs);
        playlistSongs = Next(playlistSongs);
        Stack temp;
        CreateEmptyStack(&temp);

        // Enqueue semua lagu dari playlist ke dalam antrian
        while (playlistSongs != NULL) {
            enqueue(&Antrian, Info(playlistSongs));
            PushStack(&temp, Info(playlistSongs));
            playlistSongs = Next(playlistSongs);
        }
        InvesrseStack(&temp, &Antrian);

        printf("Berhasil menambahkan playlist \"");
        PrintWord(playlistTitle);
        printf("\" ke queue.");
    } else {
        printf("Command tidak diketahui!\n\n");
    }
}