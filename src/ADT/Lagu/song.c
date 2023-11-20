#include "song.h"

// Fungsi & Prosedur untuk tipe Song

void CreateEmptyLagu(Song *lagu) {
    *lagu = CreateLagu(-1, -1, -1, -1);;
}

Song CreateLagu(int PenyanyiID, int AlbumID, int LaguID, int PlaylistID) {
    Song newSong;
    newSong.PenyanyiID = PenyanyiID;
    newSong.AlbumID = AlbumID;
    newSong.LaguID = LaguID;
    newSong.PlaylistID = PlaylistID;
    return newSong;
}

boolean SongIsEqual(Song s1, Song s2) {
    return (s1.PenyanyiID == s2.PenyanyiID) && (s1.AlbumID == s2.AlbumID) && (s1.LaguID == s2.LaguID) && (s1.PlaylistID == s2.PlaylistID);
}

// Fungsi & Prosedur untuk tipe Object

boolean ObjectIsEqual(Object o1, Object o2) {
    return (o1.ID == o2.ID) && WordCompare(o1.Title, o2.Title);
}

Object CreateObject(int ID, Word Title) {
    Object newObject;
    newObject.ID = ID;
    newObject.Title = Title;
    return newObject;
}