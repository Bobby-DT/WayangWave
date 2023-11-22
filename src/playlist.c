#include <stdio.h>
#include "playlist.h"

void playlist(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData) {
    if (WordCompare(toKata("CREATE"), toUpper(AccessCommand(currentWord, 1)))) {
        int nama_playlist_len;
        boolean playlistNotExist;
        do {
            printf("Masukkan nama playlist yang ingin dibuat : ");
            GetCommand();
            nama_playlist_len = 0;
            for (int i = 0; i < currentWord.Length; i++) {
                if (currentWord.TabWord[i] != ' ') nama_playlist_len++;
            }
            playlistNotExist = SearchArrayDinWord(*PlaylistTitle, currentWord) == -1;
            if (nama_playlist_len >= 3) {
                if (playlistNotExist) {
                    ListLinier newPlaylist;
                    CreateEmptyListLinier(&newPlaylist);
                    InsertLastArrayDinWord(PlaylistTitle, currentWord);
                    InsertLastArrayDin(PlaylistData, newPlaylist);

                    printf("Playlist ");
                    PrintWord(currentWord);
                    printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n");
                } else {
                    printf("Sudah ada Playlist dengan nama tersebut! Silakan coba lagi.\n");
                }
            } else {
                printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            }
        } while (nama_playlist_len < 3 || !playlistNotExist);
    } else if (WordCompare(toKata("ADD"), toUpper(AccessCommand(currentWord, 1)))) {
        if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 2))) || WordCompare(toKata("ALBUM"), toUpper(AccessCommand(currentWord, 2)))) {
            boolean addSong = false;
            Word namaPenyayi;
            Word namaAlbum;
            Word namaLagu;
            Word namaPlaylist;
            if (WordCompare(toKata("SONG"), toUpper(AccessCommand(currentWord, 2)))) {
                addSong = true;
            }
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
            namaPenyayi = currentWord;
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
            namaAlbum = currentWord;
            int AlbumID = searchMap(*Lagu, currentWord) + 1;
            int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;

            int LaguID;
            if (addSong) {
                PrintDaftarLagu(Penyanyi, Album, Lagu, PenyanyiID, AlbumID);
                do {
                    printf("Masukkan ID Lagu yang dipilih : ");
                    GetCommand();
                    LaguID = WordToInt(currentWord);
                    if (LaguID > AlbumLength || LaguID < 1) {
                        printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", LaguID);
                    }
                } while (LaguID > AlbumLength || LaguID < 1);
                namaLagu = GetLagu(Lagu, AlbumID, LaguID);
            }

            ListPlaylist(PlaylistTitle);
            int PlaylistID;
            do {
                printf("Masukkan ID Playlist yang dipilih : ");
                GetCommand();
                PlaylistID = WordToInt(currentWord);
                if (PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1) {
                    printf("Album %d tidak ada dalam daftar. Silakan coba lagi.\n", PlaylistID);
                }
            } while (PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1);
            namaPlaylist = GetPlaylist(PlaylistTitle, PlaylistID);

            if (addSong) {
                Song newLaguPlaylist = CreateLagu(PenyanyiID, AlbumID, LaguID, PlaylistID);
                if (SearchListLinier((*PlaylistData).A[PlaylistID - 1], newLaguPlaylist) == NULL) {
                    InsVLastListLinier(&((PlaylistData)->A[PlaylistID - 1]), newLaguPlaylist);
                    printf("Lagu dengan judul \"%s\" pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n\n", WordToStr(namaLagu), WordToStr(namaAlbum), WordToStr(namaPenyayi), WordToStr(namaPlaylist));
                } else {
                    printf("Lagu dengan judul \"%s\" pada album %s oleh penyanyi %s sudah berada dalam playlist %s.\n\n", WordToStr(namaLagu), WordToStr(namaAlbum), WordToStr(namaPenyayi), WordToStr(namaPlaylist));
                }
            } else {
                int AlbumLength = (*Lagu).Elements[AlbumID - 1].Value.length;
                for (int i = 0; i < AlbumLength; i++) {
                    Song newLaguPlaylist = CreateLagu(PenyanyiID, AlbumID, i + 1, PlaylistID);
                    if (SearchListLinier((*PlaylistData).A[PlaylistID - 1], newLaguPlaylist) == NULL) {
                        InsVLastListLinier(&((PlaylistData)->A[PlaylistID - 1]), newLaguPlaylist);
                    }
                }
                printf("Album dengan judul \"%s\" berhasil ditambahkan ke dalam pada playlist pengguna \"%s\".\n\n", WordToStr(namaAlbum), WordToStr(namaPlaylist));
            }

            
        } else {
            //PrintInfoListLinier((*PlaylistData).A[WordToInt(AccessCommand(currentWord, 2))]);
            printf("\nCommand tidak diketahui!\n\n");
        }
    } else if (WordCompare(toKata("SWAP"), toUpper(AccessCommand(currentWord, 1)))) {
        int PlaylistID = WordToInt(AccessCommand(currentWord, 2));
        boolean invalidPlaylistID = PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmtListLinier((*PlaylistData).A[PlaylistID - 1]);
            int playlistX = WordToInt(AccessCommand(currentWord, 3));
            int playlistY = WordToInt(AccessCommand(currentWord, 4));
            if (playlistX > jumlahLaguPlaylist || playlistX < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist \"", playlistX);
                PrintWord((*PlaylistTitle).A[PlaylistID - 1]);
                printf("\"\n");
            } else {
                if (playlistY > jumlahLaguPlaylist || playlistY < 1) {
                    printf("Tidak ada lagu dengan urutan %d di playlist \"", playlistY);
                    PrintWord((*PlaylistTitle).A[PlaylistID - 1]);
                    printf("\"\n");
                } else {
                    Song X = getValAtListLinier((*PlaylistData).A[PlaylistID - 1], playlistX);
                    Song Y = getValAtListLinier((*PlaylistData).A[PlaylistID - 1], playlistY);
                    setValAtListLinier(&((PlaylistData)->A[PlaylistID - 1]), playlistX, Y);
                    setValAtListLinier(&((PlaylistData)->A[PlaylistID - 1]), playlistY, X);

                    printf("Berhasil menukar lagu dengan nama \"");
                    PrintWord(GetLagu(Lagu, X.AlbumID, X.LaguID));
                    printf("\" dengan \"");
                    PrintWord(GetLagu(Lagu, Y.AlbumID, Y.LaguID));
                    printf("\" di playlist \"");
                    PrintWord((*PlaylistTitle).A[PlaylistID - 1]);
                    printf("\"\n");
                }
            }
        } else {
            printf("Tidak ada playlist dengan ID ");
            PrintWord(AccessCommand(currentWord, 2));
            printf(".\n");
        }
    } else if (WordCompare(toKata("REMOVE"), toUpper(AccessCommand(currentWord, 1)))) {
        int PlaylistID = WordToInt(AccessCommand(currentWord, 2));
        boolean invalidPlaylistID = PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1;
        if (!invalidPlaylistID) {
            int jumlahLaguPlaylist = NumberElmtListLinier((*PlaylistData).A[PlaylistID - 1]);
            int laguN = WordToInt(AccessCommand(currentWord, 3));
            if (laguN > jumlahLaguPlaylist || laguN < 1) {
                printf("Tidak ada lagu dengan urutan %d di playlist \"", laguN);
                PrintWord((*PlaylistTitle).A[PlaylistID - 1]);
                printf("\"\n");
            } else {
                Song del;
                //address beforeDel = addrAtListLinier((*PlaylistData).A[PlaylistID - 1], laguN);
                DelAtListLinier(&((PlaylistData)->A[PlaylistID - 1]), laguN, &del);
                //address afterDel = addrAtListLinier((*PlaylistData).A[PlaylistID - 1], laguN);
                printf("Lagu \"");
                PrintWord(GetLagu(Lagu, del.AlbumID, del.LaguID));
                printf("\" oleh \"");
                PrintWord(GetPenyanyi(Penyanyi, del.PenyanyiID));
                printf("\" telah dihapus dari playlist \"");
                PrintWord((*PlaylistTitle).A[PlaylistID - 1]);
                printf("\"!");
            }
        } else {
            printf("Tidak ada playlist dengan ID %d.\n", PlaylistID);
        }
    } else if (WordCompare(toKata("DELETE"), toUpper(AccessCommand(currentWord, 1)))) {
        ListPlaylist(PlaylistTitle);
        int PlaylistID;
        boolean invalidPlaylistID;
        int jumlahPlaylist = (*PlaylistTitle).Neff;
        if (jumlahPlaylist > 0){
            do {
                printf("Masukkan ID Playlist yang dipilih : ");
                GetCommand();
                PlaylistID = WordToInt(currentWord);
                invalidPlaylistID = PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1;
                if (invalidPlaylistID) {
                    printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", PlaylistID);
                }
            } while (invalidPlaylistID);
            int jumlahPlaylistSebelumnya = (*PlaylistData).Neff;
            Word playlistTitle = (*PlaylistTitle).A[PlaylistID - 1];
            DeleteAtArrayDinWord(PlaylistTitle, PlaylistID - 1);
            DeleteAtArrayDin(PlaylistData, PlaylistID - 1);
            printf("Playlist ID %d dengan judul ", PlaylistID);
            PrintWord(playlistTitle);
            if ((*PlaylistData).Neff == jumlahPlaylistSebelumnya - 1) {
                printf(" berhasil dihapus.\n");
            } else {
                printf(" gagal dihapus.\n");
            }
        }
    }
}