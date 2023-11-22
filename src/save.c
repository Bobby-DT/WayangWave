#include "save.h"

void save(Word filesrc, TabKata *Penyanyi, Map *Album, Map *Lagu, UserStorage *User, int UserID) {
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
    int jumlahUser = (*User).count;
    fprintf(file, "%d\n", jumlahUser);
    for (int i = 0; i < jumlahUser; i++) {
        fprintf(file, "%s\n", WordToStr((*User).storage[i].Username));
    }
    for (int j = 0; j < jumlahUser; j++) {
        if (!SongIsEmpty((*User).storage[j].Playing)) {
            fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, (*User).storage[j].Playing.PenyanyiID)), WordToStr(GetAlbum(Lagu, (*User).storage[j].Playing.AlbumID)), WordToStr(GetLagu(Lagu, (*User).storage[j].Playing.AlbumID, (*User).storage[j].Playing.LaguID)));
        }
        int jumlahAntrian = queue_length((*User).storage[j].Antrian);
        fprintf(file, "%d\n", jumlahAntrian);
        if (jumlahAntrian > 0) {
            if ((*User).storage[j].Antrian.idxHead <= (*User).storage[j].Antrian.idxTail) {
                for (int i = (*User).storage[j].Antrian.idxHead; i <= (*User).storage[j].Antrian.idxTail; i++) {
                    Song printAntrian = (*User).storage[j].Antrian.buffer[i];
                    fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printAntrian.PenyanyiID)), WordToStr(GetAlbum(Lagu, printAntrian.AlbumID)), WordToStr(GetLagu(Lagu, printAntrian.AlbumID, printAntrian.LaguID)));
                }
            } else {
                for (int i = (*User).storage[j].Antrian.idxHead; i < CAPACITY; i++) {
                    Song printAntrian = (*User).storage[j].Antrian.buffer[i];
                    fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printAntrian.PenyanyiID)), WordToStr(GetAlbum(Lagu, printAntrian.AlbumID)), WordToStr(GetLagu(Lagu, printAntrian.AlbumID, printAntrian.LaguID)));       
                }
                for (int i = 0; i <= (*User).storage[j].Antrian.idxTail; i++) {
                    Song printAntrian = (*User).storage[j].Antrian.buffer[i];
                    fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printAntrian.PenyanyiID)), WordToStr(GetAlbum(Lagu, printAntrian.AlbumID)), WordToStr(GetLagu(Lagu, printAntrian.AlbumID, printAntrian.LaguID)));
                }
            }
        }
        int jumlahRiwayat = Top((*User).storage[j].Riwayat) + 1;
        fprintf(file, "%d\n", jumlahRiwayat);
        for (int i = 0; i < jumlahRiwayat; i++) {
            int printIdx = Top((*User).storage[j].Riwayat) - i;
            Song printRiwayat = (*User).storage[j].Riwayat.T[printIdx];
            fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printRiwayat.PenyanyiID)), WordToStr(GetAlbum(Lagu, printRiwayat.AlbumID)), WordToStr(GetLagu(Lagu, printRiwayat.AlbumID, printRiwayat.LaguID)));
        }
        int jumlahPlaylist = (*User).storage[j].PlaylistData.Neff;
        fprintf(file, "%d\n", jumlahPlaylist);
        for (int i = 0; i < jumlahPlaylist; i++) {
            int jumlahLaguPlaylist = NumberElmtListLinier((*User).storage[j].PlaylistData.A[i]);
            fprintf(file, "%d %s\n", jumlahLaguPlaylist, WordToStr((*User).storage[j].PlaylistTitle.A[i]));
            address playlistSongs = First((*User).storage[j].PlaylistData.A[i]);
            for (int j = 0; j < jumlahLaguPlaylist; j++) {
                Song printPlaylist = Info(playlistSongs);
                fprintf(file, "%s;%s;%s\n", WordToStr(GetPenyanyi(Penyanyi, printPlaylist.PenyanyiID)), WordToStr(GetAlbum(Lagu, printPlaylist.AlbumID)), WordToStr(GetLagu(Lagu, printPlaylist.AlbumID, printPlaylist.LaguID)));
                playlistSongs = Next(playlistSongs);
            }
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