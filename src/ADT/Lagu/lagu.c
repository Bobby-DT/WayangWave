#include "lagu.h"

// Fungsi & Prosedur untuk tipe Song

void CreateEmptyLagu(Song *lagu) {
    Song EmptySong = CreateLagu(NULL, NULL, NULL, -1);
    *lagu = EmptySong;
}

Song CreateLagu(int PenyanyiID, int AlbumID, int PenyanyiID, int PlaylistID) {
    Song newSong;
    newSong.PenyanyiID = PenyanyiID;
    newSong.AlbumID = AlbumID;
    newSong.LaguID = PenyanyiID;
    newSong.PlaylistID = PlaylistID;
    return newSong;
}

Word GetPenyanyi(TabKata *Penyanyi, int PenyanyiID) {
    return (*Penyanyi).TK[PenyanyiID - 1];
}

Word GetAlbum(Map *Album, int AlbumID) {
    return (*Album).Elements[AlbumID - 1].Key;
}

Word GetLagu(Map *Album, Map *Lagu, int AlbumID, int LaguID) {
    return (*Lagu).Elements[AlbumID - 1].Value.buffer[LaguID - 1].Title;
}

Word GetPlaylist(ArrayDinWord *PlaylistTitle, int PlaylistID) {
    return (*PlaylistTitle).TK[PlaylistID - 1];
}

boolean SongIsEqual(Song s1, Song s2) {
    return (s1.PenyanyiID == s2.PenyanyiID) && (s1.AlbumID == s2.AlbumID) && (s1.LaguID == s2.LaguID) && (s1.PlaylistID == s2.PlaylistID);
}

void PrintSong(TabKata *Penyanyi, Map *Album, Map *Lagu, int PenyanyiID, int AlbumID, int LaguID) {
    PrintWord(GetPenyanyi(&Penyanyi, PlaylistID));
    printf(" - ");
    PrintWord(GetLagu(&Album, &Lagu, AlbumID, LaguID));
    printf(" - ");
    PrintWord(GetAlbum(&Album, AlbumID));
}

// Fungsi & Prosedur untuk tipe Object

boolean ObjectIsEqual(Object o1, Object o2) {
    return (o1.ID == o2.ID) && WordCompare(o1.Title, o2.Title);
}

Object CreateObject(int ID, Word Title) {
    Object newObject;
    newObject.ID = ID;
    newObject.Title = Title;
    return Object;
}