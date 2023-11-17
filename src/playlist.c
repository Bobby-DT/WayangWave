#include <stdio.h>
#include "playlist.h"

void playlist(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData) {
    GetCommand();
    if (WordCompare(toKata("CREATE"), AccessCommand(currentWord, 1))) {
        do {
            printf("Masukkan nama playlist yang ingin dibuat : ");
            GetCommand();
            int nama_playlist_len = 0;
            for (int i = 0; i < currentWord.Length; i++) {
                if (currentWord.TabWord[i] != ' ') nama_playlist_len++;
            }
            if (nama_playlist_len >= 3) {
                if (SearchArrayDinWord(&PlaylistTitle, currentWord) == -1) {
                    List newPlaylist;
                    CreateEmptyList(&newPlaylist);
                    InsertLastArrayDinWord(PlaylistTitle, currentWord);
                    InsertLastArrayDin(PlaylistData, newPlaylist);

                    printf("Playlist ");
                    TulisWord(currentWord);
                    printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
                } else {
                    printf("Sudah ada Playlist dengan nama tersebut! Silakan coba lagi.\n");
                }
            } else {
                printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            }
        } while (!(nama_playlist_len >= 3) || SearchArrayDinWord(&PlaylistTitle, currentWord) != -1);
    } else if (WordCompare(toKata("ADD"), AccessCommand(currentWord, 1))) {
        if (!WordCompare(toKata("SONG"), AccessCommand(currentWord, 2)) && !WordCompare(toKata("ALBUM"), AccessCommand(currentWord, 2))) {
            boolean addSong = false;
            if (WordCompare(toKata("SONG"), AccessCommand(currentWord, 2))) {
                addSong = true;
            }
            printf("Daftar Penyanyi :");
            for (int i = 0; i < (*Penyanyi).Count; i++) {
                printf("\n\t%d. ", i+1);
                TulisWord((*Penyanyi).TK[i]);
            }
            printf("\n");
            do {
                printf("Masukkan Nama Penyanyi yang dipilih : ");
                GetCommand();
                if (!IsMember(&Penyanyi, currentWord)) {
                    printf("Penyanyi ");
                    TulisWord(currentWord);
                    printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
                }
            } while (!IsMember(&Penyanyi, currentWord));
            int PenyanyiID = searchList(&Penyanyi, currentWord) + 1;

            printf("Daftar Album oleh ");
            TulisWord(currentWord);
            printf(" :\n");
            for (int i = 0; i < (*Album).Elements[PenyanyiID - 1].Value.length; i++) {
                printf("\n\t%d. ", i+1);
                TulisWord((*Album).Elements[PenyanyiID - 1].Value.buffer[i]);
            }
            printf("\n");

            do {
                printf("Masukkan Judul Album yang dipilih : ");
                GetCommand();
                if (!MapIsMember(&Album, currentWord)) {
                    printf("Album ");
                    TulisWord(currentWord);
                    printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
                }
            } while (!MapIsMember(&Album, currentWord));
            int AlbumID = searchMap(&Album, currentWord) + 1;

            if (addSong) {
                printf("Daftar Lagu Album ");
                TulisWord((*Album).Elements[PenyanyiID - 1].Value.buffer[AlbumID - 1]);
                printf(" oleh ");
                TulisWord((*Penyanyi).TK[PenyanyiID - 1]);
                printf(" :\n");

                int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;
                for (int i = 0; i < AlbumLength; i++) {
                    printf("\n\t%d. ", i+1);
                    TulisWord((*Lagu).Elements[AlbumID - 1].Value.buffer[i]);
                }
                printf("\n");

                do {
                    printf("Masukkan ID Lagu yang dipilih : ");
                    GetCommand();
                    if (WordToInt(currentWord) >= AlbumLength) {
                        printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
                    }
                } while (WordToInt(currentWord) >= AlbumLength);  
                int LaguID = WordToInt(currentWord);
            }

            printf("Daftar Playlist Pengguna :\n");
            for (int i = 0; i < (*PlaylistTitle).Neff; i++) {
                printf("\n\t%d. ", i+1);
                TulisWord((*PlaylistTitle).A[i]);
            }
            printf("\n");

            do {
                printf("Masukkan ID Playlist yang dipilih : ");
                GetCommand();
                if (WordToInt(currentWord) >= (*PlaylistTitle).Neff) {
                    printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
                }
            } while (WordToInt(currentWord) >= (*PlaylistTitle).Neff);
            int PlaylistID = WordToInt(currentWord) >= (*PlaylistTitle).Neff;

            if (addSong) {
                Lagu newLaguPlaylist;
                newLaguPlaylist.PenyanyiID = PenyanyiID;
                newLaguPlaylist.AlbumID = AlbumID;
                newLaguPlaylist.LaguID = LaguID;
                InsVLastListLinier((*PlaylistData).[PlaylistID - 1], newLaguPlaylist);
            } else {
                int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;
                Lagu newLaguPlaylist;
                newLaguPlaylist.PenyanyiID = PenyanyiID;
                newLaguPlaylist.AlbumID = AlbumID;
                for (int i = 0; i < AlbumLength; i++) {
                    newLaguPlaylist.LaguID = i + 1;
                    InsVLastListLinier((*PlaylistData).[PlaylistID - 1], newLaguPlaylist);
                }
            }
        } else {
            printf("Command tidak diketahui!\n\n");
        }
    } else if (WordCompare(toKata("SWAP"), AccessCommand(currentWord, 1))) {
        int playlistID = WordToInt(AccessCommand(currentWord, 2)) + 1;
        boolean invalidPlaylistID = playlistID > (*PlaylistTitle).Neff || playlistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmt((*PlaylistData).A[playlistID - 1]);
            int playlistX = WordToInt(AccessCommand(currentWord, 3));
            int playlistY = WordToInt(AccessCommand(currentWord, 4));
            if (playlistX > jumlahLaguPlaylist || playlistX < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist “", playlistX);
                TulisWord((*PlaylistTitle).A[playlistID - 1]);
                printf("”\n");
            } else {
                if (playlistY > jumlahLaguPlaylist || playlistY < 1) {
                    printf("Tidak ada lagu dengan urutan %d di playlist “", playlistY);
                    TulisWord((*PlaylistTitle).A[playlistID - 1]);
                    printf("”\n");
                } else {
                    // swap playlist

                    if (/*swap berhasil*/) {
                        printf("Berhasil menukar lagu dengan nama “");
                        TulisWord(/**/);
                        printf("” dengan “");
                        TulisWord(/**/);
                        printf("” di playlist “");
                        TulisWord((*PlaylistTitle).A[playlistID - 1]);
                        printf("”\n");
                    }
                }
            }
        } else {
            print("Tidak ada playlist dengan ID ");
            TulisWord(AccessCommand(currentWord, 2));
            printf(".\n");
        }
    } else if (WordCompare(toKata("REMOVE"), AccessCommand(currentWord, 1))) {
        int playlistID = WordToInt(AccessCommand(currentWord, 2)) + 1;
        boolean invalidPlaylistID = playlistID > (*PlaylistTitle).Neff || playlistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmt((*PlaylistData).A[playlistID - 1]);
            int laguN = WordToInt(AccessCommand(currentWord, 3));
            if (laguN > jumlahLaguPlaylist || laguN < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist “", laguN);
                TulisWord((*PlaylistTitle).A[playlistID - 1]);
                printf("”\n");
            } else {
                //address beforeDel = addrAtListLinier((*PlaylistData).A[playlistID - 1], laguN);
                DelAtListLinier((*PlaylistData), laguN);
                //address afterDel = addrAtListLinier((*PlaylistData).A[playlistID - 1], laguN);
                if (true) {
                    printf("Lagu “");
                    TulisWord(/*lagu*/);
                    printf("” oleh “");
                    TulisWord(/*penyanyi*/);
                    printf("” telah dihapus dari playlist “");
                    TulisWord((*PlaylistTitle).A[playlistID - 1]);
                    printf("”!");
                } else {
                    printf("Lagu “");
                    TulisWord(/*lagu*/);
                    printf("” oleh “");
                    TulisWord(/*penyanyi*/);
                    printf("” gagal dihapus dari playlist “");
                    TulisWord((*PlaylistTitle).A[playlistID - 1]);
                    printf("”!");
                }
            }
        } else {
            printf("Tidak ada playlist dengan ID %d.\n", playlistID);
        }
    } else if (WordCompare(toKata("DELETE"), AccessCommand(currentWord, 1))) {
        printf("Daftar Playlist Pengguna :\n");
        for (int i = 0; i < (*PlaylistTitle).Neff; i++) {
            printf("\n\t%d. ", i+1);
            TulisWord((*PlaylistTitle).A[i]);
        }
        printf("\n")

        do {
            printf("Masukkan ID Playlist yang dipilih : ");
            GetCommand();
            int playlistID = WordToInt(currentWord) + 1;
            boolean invalidPlaylistID = playlistID > (*PlaylistTitle).Neff || playlistID < 1;
            if (invalidPlaylistID) {
                printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", playlistID);
            }
        } while (invalidPlaylistID);
        int jumlahPlaylistSebelumnya = (*PlaylistData).Neff;
        Word playlistTitle = (*PlaylistTitle).A[playlistID - 1];
        DeleteAtArrayDinWord(*PlaylistTitle, playlistID);
        DeleteAtArrayDin(*PlaylistData, playlistID);
        printf("Playlist ID %d dengan judul ", playlistID);
        TulisWord(playlistTitle);
        if ((*PlaylistData).Neff == jumlahPlaylistSebelumnya - 1) {
            printf(" berhasil dihapus.\n");
        } else {
            printf(" gagal dihapus.\n");
        }
    }
}