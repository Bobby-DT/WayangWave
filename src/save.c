#include "save.h"

void save(Word filesrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    char dir[50] = "../save/";
    for (int i = 0; i < filesrc.Length; i++) {
        dir[8 + i] = filesrc.TabWord[i];
    }
    dir[8 + filesrc.Length] = '\0';

    FILE* file = fopen(dir, "w");
    fprintf(file, "%d\n", (*Penyanyi).Neff);
    for (int i = 0; i < (*Penyanyi).Neff; i++) {
        int jumlahAlbum = (*Album).Elements[i].Value.length;
        fprintf(file, "%d %s\n", jumlahAlbum, WordToStr((*Penyanyi).TK[i]));
        for (int j = 0; j < jumlahAlbum; j++) {
            int AlbumID = (*Album).Elements[i].Value.buffer[j].ID;
            int jumlahLagu = (*Lagu).Elements[AlbumID - 1].Value.length;
            fprintf(file, "%d %s\n", jumlahLagu, WordToStr((*Album).Elements[i].Value.buffer[j].Title));
            for (int k = 0; k < jumlahLagu; k++) {
                fprintf(file, "%s\n", WordToStr((*Lagu).Elements[AlbumID - 1].Value.buffer[k].Title));
            }
        }
    }
    if (!SongIsEmpty(*Playing)) {
        fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, (*Playing).PenyanyiID)), WordToStr(GetAlbum(Lagu, (*Playing).AlbumID)), WordToStr(GetLagu(Lagu, (*Playing).AlbumID, (*Playing).LaguID)));
    }
    int jumlahAntrian = queue_length(*Antrian);
    fprintf(file, "%d\n", jumlahAntrian);
    if ((*Antrian).idxHead <= (*Antrian).idxTail) {
        for (int i = (*Antrian).idxHead; i <= (*Antrian).idxTail; i++) {
            Song printAntrian = (*Antrian).buffer[i];
            fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printAntrian.PenyanyiID)), WordToStr(GetAlbum(Lagu, printAntrian.AlbumID)), WordToStr(GetLagu(Lagu, printAntrian.AlbumID, printAntrian.LaguID)));
        }
    } else {
        for (int i = (*Antrian).idxHead; i < CAPACITY; i++) {
            Song printAntrian = (*Antrian).buffer[i];
            fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printAntrian.PenyanyiID)), WordToStr(GetAlbum(Lagu, printAntrian.AlbumID)), WordToStr(GetLagu(Lagu, printAntrian.AlbumID, printAntrian.LaguID)));       
        }
        for (int i = 0; i <= (*Antrian).idxTail; i++) {
            Song printAntrian = (*Antrian).buffer[i];
            fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printAntrian.PenyanyiID)), WordToStr(GetAlbum(Lagu, printAntrian.AlbumID)), WordToStr(GetLagu(Lagu, printAntrian.AlbumID, printAntrian.LaguID)));
        }
    }
    int jumlahRiwayat = Top(*Riwayat) + 1;
    fprintf(file, "%d\n", jumlahRiwayat);
    for (int i = 0; i < jumlahRiwayat; i++) {
        int printIdx = Top(*Riwayat) - i;
        Song printRiwayat = (*Riwayat).T[printIdx];
        fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printRiwayat.PenyanyiID)), WordToStr(GetAlbum(Lagu, printRiwayat.AlbumID)), WordToStr(GetLagu(Lagu, printRiwayat.AlbumID, printRiwayat.LaguID)));
    }
    int jumlahPlaylist = (*PlaylistData).Neff;
    fprintf(file, "%d\n", jumlahPlaylist);
    for (int i = 0; i < jumlahPlaylist; i++) {
        int jumlahLaguPlaylist = NumberElmtListLinier((*PlaylistData).A[i]);
        fprintf(file, "%d %s\n", jumlahLaguPlaylist, WordToStr((*PlaylistTitle).A[i]));
        address playlistSongs = First((*PlaylistData).A[i]);
        for (int j = 0; j < jumlahLaguPlaylist; j++) {
            Song printPlaylist = Info(playlistSongs);
            fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printPlaylist.PenyanyiID)), WordToStr(GetAlbum(Lagu, printPlaylist.AlbumID)), WordToStr(GetLagu(Lagu, printPlaylist.AlbumID, printPlaylist.LaguID)));
            playlistSongs = Next(playlistSongs);
        }
    }
    fprintf(file, " ");
    fclose(file);

    FILE* check = fopen(dir, "r");
    if (check != NULL) {
        printf("Save file berhasil disimpan.\n\n");
    } else {
        printf("Save file gagal disimpan.\n\n");
    }
    fclose(check);
}