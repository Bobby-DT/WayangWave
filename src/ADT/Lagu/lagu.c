#include "lagu.h"

Word GetPenyanyi(TabKata *Penyanyi, int PenyanyiID) {
    return (*Penyanyi).TK[PenyanyiID - 1];
}

Word GetAlbum(Map *Lagu, int AlbumID) {
    return (*Lagu).Elements[AlbumID - 1].Key;
}

Word GetLagu(Map *Lagu, int AlbumID, int LaguID) {
    return (*Lagu).Elements[AlbumID - 1].Value.buffer[LaguID - 1].Title;
}

Word GetPlaylist(ArrayDinWord *PlaylistTitle, int PlaylistID) {
    return (*PlaylistTitle).A[PlaylistID - 1];
}

int GetPenyanyiID(TabKata *Penyanyi, Word namaPenyanyi) {
    for (int i = 0; i < (*Penyanyi).Neff; i++) {
		if (WordCompare((*Penyanyi).TK[i], namaPenyanyi)) {
			return i;
		}
	}
	return -1;
}

int GetAlbumID(Map *Album, Word namaAlbum, int PenyanyiID) {
    Set AlbumofPenyanyi = (*Album).Elements[PenyanyiID - 1].Value;
    int albumLength = AlbumofPenyanyi.length;
    int i = 0;
    boolean found = false;
    while (!found && i < albumLength) {
        if (WordCompare(AlbumofPenyanyi.buffer[i].Title, namaAlbum)) {
            return AlbumofPenyanyi.buffer[i].ID;
        }
        i++;
    }
    return -1;
}

int GetLaguID(Map *Lagu, Word namaLagu, int AlbumID) {
    Set LaguofAlbum = (*Lagu).Elements[AlbumID - 1].Value;
    int laguLength = LaguofAlbum.length;
    int i = 0;
    boolean found = false;
    while (!found && i < laguLength) {
        if (WordCompare(LaguofAlbum.buffer[i].Title, namaLagu)) {
            return LaguofAlbum.buffer[i].ID;
        }
        i++;
    }
    return -1;
}

int GetPlaylistID(ArrayDinWord *PlaylistTitle, Word namaPlaylist) {
    int j = 0;
	while (!WordCompare((*PlaylistTitle).A[j], namaPlaylist) && (j <= (*PlaylistTitle).Neff)) {
		j++;
	}
	if (j > (*PlaylistTitle).Neff) {
		j = -2;
	}
	return j + 1;
}

void PrintSong(TabKata *Penyanyi, Map *Album, Map *Lagu, int PenyanyiID, int AlbumID, int LaguID) {
    PrintWord(GetPenyanyi(Penyanyi, PenyanyiID));
    printf(" - ");
    PrintWord(GetLagu(Lagu, AlbumID, LaguID));
    printf(" - ");
    PrintWord(GetAlbum(Lagu, AlbumID));
}