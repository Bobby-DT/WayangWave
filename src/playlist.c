#include <stdio.h>
#include "playlist.h"

void playlist(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData) {
    GetCommand();
    if (WordCompare(toKata("CREATE"), toUpper(AccessCommand(currentWord, 1)))) {
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
                    PrintWord(currentWord);
                    printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
                } else {
                    printf("Sudah ada Playlist dengan nama tersebut! Silakan coba lagi.\n");
                }
            } else {
                printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            }
        } while (!(nama_playlist_len >= 3) || SearchArrayDinWord(&PlaylistTitle, currentWord) != -1);
    } else if (WordCompare(toKata("ADD"), toUpper(AccessCommand(currentWord, 1)))) {
        if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 2))) && WordCompare(toKata("ALBUM"), toUpper(AccessCommand(currentWord, 2)))) {
            boolean addSong = false;
            if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 2)))) {
                addSong = true;
            }
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

            if (addSong) {
                PrintDaftarLagu(&Penyanyi, &Album, &Lagu, PenyanyiID, AlbumID);

                do {
                    printf("Masukkan ID Lagu yang dipilih : ");
                    GetCommand();
                    if (WordToInt(currentWord) >= AlbumLength) {
                        printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
                    }
                } while (WordToInt(currentWord) >= AlbumLength);  
                int LaguID = WordToInt(currentWord);
            }

            ListPlaylist(&PlaylistTitle);

            do {
                printf("Masukkan ID Playlist yang dipilih : ");
                GetCommand();
                if (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0) {
                    printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", WordToInt(currentWord));
                }
            } while (WordToInt(currentWord) >= (*PlaylistTitle).Neff || WordToInt(currentWord) < 0);
            int PlaylistID = WordToInt(currentWord);

            if (addSong) {
                Song newLaguPlaylist = CreateLagu(PenyanyiID, AlbumID, LaguID, PlaylistID);
                InsVLastListLinier((*PlaylistData).[PlaylistID - 1], newLaguPlaylist);
            } else {
                int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;
                for (int i = 0; i < AlbumLength; i++) {
                    Song newLaguPlaylist = CreateLagu(PenyanyiID, AlbumID, i + 1, PlaylistID);
                    InsVLastListLinier((*PlaylistData).[PlaylistID - 1], newLaguPlaylist);
                }
            }
        } else {
            printf("Command tidak diketahui!\n\n");
        }
    } else if (WordCompare(toKata("SWAP"), toUpper(AccessCommand(currentWord, 1)))) {
        int playlistID = WordToInt(AccessCommand(currentWord, 2)) + 1;
        boolean invalidPlaylistID = playlistID > (*PlaylistTitle).Neff || playlistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmt((*PlaylistData).A[playlistID - 1]);
            int playlistX = WordToInt(AccessCommand(currentWord, 3));
            int playlistY = WordToInt(AccessCommand(currentWord, 4));
            if (playlistX > jumlahLaguPlaylist || playlistX < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist “", playlistX);
                PrintWord((*PlaylistTitle).A[playlistID - 1]);
                printf("”\n");
            } else {
                if (playlistY > jumlahLaguPlaylist || playlistY < 1) {
                    printf("Tidak ada lagu dengan urutan %d di playlist “", playlistY);
                    PrintWord((*PlaylistTitle).A[playlistID - 1]);
                    printf("”\n");
                } else {
                    // swap playlist

                    if (/*swap berhasil*/) {
                        printf("Berhasil menukar lagu dengan nama “");
                        PrintWord(/**/);
                        printf("” dengan “");
                        PrintWord(/**/);
                        printf("” di playlist “");
                        PrintWord((*PlaylistTitle).A[playlistID - 1]);
                        printf("”\n");
                    }
                }
            }
        } else {
            print("Tidak ada playlist dengan ID ");
            PrintWord(AccessCommand(currentWord, 2));
            printf(".\n");
        }
    } else if (WordCompare(toKata("REMOVE"), toUpper(AccessCommand(currentWord, 1)))) {
        int playlistID = WordToInt(AccessCommand(currentWord, 2)) + 1;
        boolean invalidPlaylistID = playlistID > (*PlaylistTitle).Neff || playlistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmt((*PlaylistData).A[playlistID - 1]);
            int laguN = WordToInt(AccessCommand(currentWord, 3));
            if (laguN > jumlahLaguPlaylist || laguN < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist “", laguN);
                PrintWord((*PlaylistTitle).A[playlistID - 1]);
                printf("”\n");
            } else {
                //address beforeDel = addrAtListLinier((*PlaylistData).A[playlistID - 1], laguN);
                DelAtListLinier((*PlaylistData), laguN);
                //address afterDel = addrAtListLinier((*PlaylistData).A[playlistID - 1], laguN);
                if (true) {
                    printf("Lagu “");
                    PrintWord(/*lagu*/);
                    printf("” oleh “");
                    PrintWord(/*penyanyi*/);
                    printf("” telah dihapus dari playlist “");
                    PrintWord((*PlaylistTitle).A[playlistID - 1]);
                    printf("”!");
                } else {
                    printf("Lagu “");
                    PrintWord(/*lagu*/);
                    printf("” oleh “");
                    PrintWord(/*penyanyi*/);
                    printf("” gagal dihapus dari playlist “");
                    PrintWord((*PlaylistTitle).A[playlistID - 1]);
                    printf("”!");
                }
            }
        } else {
            printf("Tidak ada playlist dengan ID %d.\n", playlistID);
        }
    } else if (WordCompare(toKata("DELETE"), toUpper(AccessCommand(currentWord, 1)))) {
        ListPlaylist(&PlaylistTitle);

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
        PrintWord(playlistTitle);
        if ((*PlaylistData).Neff == jumlahPlaylistSebelumnya - 1) {
            printf(" berhasil dihapus.\n");
        } else {
            printf(" gagal dihapus.\n");
        }
    }
}