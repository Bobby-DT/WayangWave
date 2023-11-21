#include "play.h"

void play(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 1)))) {
        PrintDaftarPenyanyi(Penyanyi);
        do {
            printf("Masukkan Nama Penyanyi yang dipilih : ");
            GetCommand();
            if (!IsMember(*Penyanyi, currentWord)) {
                printf("Penyanyi ");
                PrintWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!IsMember(*Penyanyi, currentWord));
        int PenyanyiID = searchList(*Penyanyi, currentWord) + 1;

        PrintDaftarAlbum(Penyanyi, Album, PenyanyiID);
        do {
            printf("Masukkan Judul Album yang dipilih : ");
            GetCommand();
            if (!MapIsMember(*Lagu, currentWord)) {
                printf("Album ");
                PrintWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        } while (!MapIsMember(*Lagu, currentWord));
        int AlbumID = searchMap(*Lagu, currentWord) + 1;
        int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;

        PrintDaftarLagu(Penyanyi, Album, Lagu, PenyanyiID, AlbumID);

        int LaguID;
        do {
            printf("Masukkan ID Lagu yang dipilih : ");
            GetCommand();
            LaguID = WordToInt(currentWord);
            if (LaguID > AlbumLength || LaguID < 1) {
                printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", LaguID);
            }
        } while (LaguID > AlbumLength || LaguID < 1);

        *Playing = CreateLagu(PenyanyiID, AlbumID, LaguID, -1);
        while (!queue_isEmpty(*Antrian)) {
            Song del;
            dequeue(Antrian, &del);
        }
        while (!IsEmptyStack(*Riwayat)) {
            Song del;
            PopStack(Riwayat, &del);
        }

        printf("Memutar lagu \"");
        PrintWord(GetLagu(Lagu, AlbumID, LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(Penyanyi, PenyanyiID));
        printf("\"\n\n");
    } else if (WordCompare(toKata("PLAYLIST"), toUpper(AccessCommand(currentWord, 1)))) {
        ListPlaylist(PlaylistTitle);

        int jumlahPlaylist = (*PlaylistTitle).Neff;

        if (jumlahPlaylist > 0){
            int PlaylistID;
            do {
                printf("Masukkan ID Playlist yang dipilih : ");
                GetCommand();
                PlaylistID = WordToInt(currentWord);
                if (PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1) {
                    printf("Playlist dengan ID %d tidak ada dalam daftar. Silakan coba lagi.\n", PlaylistID);
                }
            } while (PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1);
            Word playlistTitle = (*PlaylistTitle).A[PlaylistID - 1];
            
            // Ambil informasi lagu dari playlist dengan ID tertentu
            address playlistSongs = First((*PlaylistData).A[PlaylistID - 1]);

            *Playing = Info(playlistSongs);
            playlistSongs = Next(playlistSongs);
            Stack temp;
            CreateEmptyStack(&temp);

            // Enqueue semua lagu dari playlist ke dalam antrian
            while (playlistSongs != NULL) {
                enqueue(Antrian, Info(playlistSongs));
                PushStack(&temp, Info(playlistSongs));
                playlistSongs = Next(playlistSongs);
            }
            InvesrseStack(&temp, Riwayat);

        printf("Berhasil menambahkan playlist \"");
        PrintWord(playlistTitle);
        printf("\" ke queue.\n\n");
        }
    } else {
        printf("Command tidak diketahui!\n\n");
    }
}