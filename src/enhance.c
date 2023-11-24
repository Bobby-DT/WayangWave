#include "enhance.h"

int randomInt(int max_num) {
    clock_t time = clock();
    return time % max_num;
}

void addRandomSong(TabKata *Penyanyi, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, int PlaylistID, int playlistSongID) {
    printf("\nMenambahkan Lagu pada Playlist dengan lagu random");
    printf("\nLagu yang ditambahkan: ");
    int jumlahLaguRekomendasi = 0;
    while (jumlahLaguRekomendasi < 3) {
        int penyayiRekomendasi = randomInt((*Penyanyi).Neff);
        int albumRekomendasi = randomInt((*Album).Elements[penyayiRekomendasi - 1].Value.length);
        int laguRekomendasi = randomInt((*Lagu).Elements[albumRekomendasi - 1].Value.length);
        Song rekomendasi = CreateLagu(penyayiRekomendasi, albumRekomendasi, laguRekomendasi, PlaylistID);
        if (SearchListLinier((*PlaylistData).A[PlaylistID - 1], rekomendasi) == NULL) {
            printf("\n\t%d. ", playlistSongID + jumlahLaguRekomendasi);
            PrintSong(Penyanyi, Album, Lagu, rekomendasi.PenyanyiID, rekomendasi.AlbumID, rekomendasi.LaguID);
            InsVLastListLinier(&((PlaylistData)->A[PlaylistID - 1]), rekomendasi);
            jumlahLaguRekomendasi++;
        }
    }
}

void enhance(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData) {
    ListPlaylist(PlaylistTitle);
    int PlaylistID;
    boolean invalidPlaylistID;
    int jumlahPlaylist = (*PlaylistTitle).Neff;
    if (jumlahPlaylist > 0){
        do {
            printf("Masukkan Nama Playlist yang akan di-enhance : ");
            GetCommand();
            PlaylistID = SearchArrayDinWord(*PlaylistTitle, currentWord) + 1;
            invalidPlaylistID = PlaylistID > (*PlaylistTitle).Neff || PlaylistID < 1;
            if (invalidPlaylistID) {
                printf("Tidak ada playlist dengan dengan nama tersebut. Silakan coba lagi.\n");
            }
        } while (invalidPlaylistID);
        address playlistSongs = First((*PlaylistData).A[PlaylistID - 1]);

        int playlistSongID = 1;
        int jumlahAlbum = (*Lagu).Count;
        int jumlahLaguPlaylist = 0;

        printf("Lagu yang berada pada playlist \"%s\": ", WordToStr((*PlaylistTitle).A[PlaylistID - 1]));
        while (playlistSongs != NULL) {
            Song laguPlaylist = Info(playlistSongs);
            jumlahLaguPlaylist++;
            printf("\n\t%d. ", playlistSongID);
            PrintSong(Penyanyi, Album, Lagu, laguPlaylist.PenyanyiID, laguPlaylist.AlbumID, laguPlaylist.LaguID);
            playlistSongs = Next(playlistSongs);
            playlistSongID++;
        }
        int jumlahRiwayat, LaguID;
        int i = 0, j = 0, jumlahLaguRekomendasi = 0;
        if (playlistSongID == 1) {
            jumlahRiwayat = NbElmtStack(*Riwayat);
            if (jumlahRiwayat == 0) {
                // Menambahkan Lagu pada Playlist dengan lagu random
                addRandomSong(Penyanyi, Album, Lagu, PlaylistTitle, PlaylistData, PlaylistID, playlistSongID);
            } else {
                // Menambahkan Lagu pada Playlist berdasarkan lagu yang
                // pernah dimainkan (Riwayat)
                while (jumlahLaguRekomendasi < 3 && i < jumlahRiwayat) {
                    int riwayatIdx = (*Riwayat).TOP - i;
                    int penyayiRekomendasi = (*Riwayat).T[riwayatIdx].PenyanyiID;
                    int albumRekomendasi = (*Riwayat).T[riwayatIdx].AlbumID;
                    int panjangAlbumRekomendasi = (*Lagu).Elements[albumRekomendasi - 1].Value.length;
                    printf("\nMenambahkan Lagu pada Playlist berdasarkan lagu yang pernah dimainkan");
                    printf("\nLagu yang ditambahkan: ");
                    while (jumlahLaguRekomendasi < 3 || j < panjangAlbumRekomendasi) {
                        LaguID = (*Lagu).Elements[albumRekomendasi - 1].Value.buffer[j].ID;
                        Song laguRekomendasi = CreateLagu(penyayiRekomendasi, albumRekomendasi, LaguID, PlaylistID);
                        if (SearchListLinier((*PlaylistData).A[PlaylistID - 1], laguRekomendasi) == NULL) {
                            printf("\n\t%d. ", playlistSongID + jumlahLaguRekomendasi);
                            PrintSong(Penyanyi, Album, Lagu, laguRekomendasi.PenyanyiID, laguRekomendasi.AlbumID, laguRekomendasi.LaguID);
                            InsVLastListLinier(&((PlaylistData)->A[PlaylistID - 1]), laguRekomendasi);
                            jumlahLaguRekomendasi++;
                        }
                        j++;
                    }
                    i++;
                }
            }
        } else {
            // Menambahkan Lagu pada Playlist berdasarkan lagu yang
            // berada pada playlist tersebut
            playlistSongs = First((*PlaylistData).A[PlaylistID - 1]);
            while (jumlahLaguRekomendasi < 3 && i < jumlahLaguPlaylist) {
                Song laguPlaylist = Info(playlistSongs);
                int penyayiRekomendasi = laguPlaylist.PenyanyiID;
                int albumRekomendasi = laguPlaylist.AlbumID;
                int panjangAlbumRekomendasi = (*Lagu).Elements[albumRekomendasi - 1].Value.length;
                printf("\nMenambahkan Lagu pada Playlist berdasarkan lagu yang berada pada playlist tersebut");
                printf("\nLagu yang ditambahkan: ");
                while (jumlahLaguRekomendasi < 3 || j < panjangAlbumRekomendasi) {
                    LaguID = (*Lagu).Elements[albumRekomendasi - 1].Value.buffer[j].ID;
                    Song laguRekomendasi = CreateLagu(penyayiRekomendasi, albumRekomendasi, LaguID, PlaylistID);
                    if (SearchListLinier((*PlaylistData).A[PlaylistID - 1], laguRekomendasi) == NULL) {
                        printf("\n\t%d. ", playlistSongID + jumlahLaguRekomendasi);
                        PrintSong(Penyanyi, Album, Lagu, laguRekomendasi.PenyanyiID, laguRekomendasi.AlbumID, laguRekomendasi.LaguID);
                        InsVLastListLinier(&((PlaylistData)->A[PlaylistID - 1]), laguRekomendasi);
                        jumlahLaguRekomendasi++;
                    }
                    j++;
                }
                playlistSongs = Next(playlistSongs);
                i++;
            }
        }
        if (jumlahLaguRekomendasi == 0) {
            // Menambahkan Lagu pada Playlist dengan lagu random
            addRandomSong(Penyanyi, Album, Lagu, PlaylistTitle, PlaylistData, PlaylistID, playlistSongID);
        }
    }
    printf("\n\n");
}