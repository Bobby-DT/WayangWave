#include "lagu.h"

// Fungsi & Prosedur untuk tipe Song

void CreateEmptyLagu(Song *lagu) {
    Song EmptySong = CreateLagu(NULL, NULL, NULL);
    *lagu = EmptySong;
}

Song CreateLagu(IDtype PenyanyiID, IDtype AlbumID, IDtype PenyanyiID) {
    Song newSong;
    newSong.PenyanyiID = PenyanyiID;
    newSong.AlbumID = AlbumID;
    newSong.LaguID = PenyanyiID;
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

boolean SongIsEqual(Song s1, Song s2) {
    return (s1.PenyanyiID == s2.PenyanyiID) && (s1.AlbumID == s2.AlbumID) && (s1.LaguID == s2.LaguID);
}

// Fungsi & Prosedur untuk tipe Object

boolean ObjectIsEqual(Object o1, Object o2) {
    return (o1.ID == o2.ID) && WordCompare(o1.Title, o2.Title);
}

Object CreateObject(IDtype ID, Titletype Title) {
    Object newObject;
    newObject.ID = ID;
    newObject.Title = Title;
    return Object;
}