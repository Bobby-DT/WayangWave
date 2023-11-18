#ifndef lagu_H
#define lagu_H

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"

typedef struct {
    int PenyanyiID;
    int AlbumID;
    int LaguID;
    int PlaylistID;
} Song;

typedef struct {
    int ID;
    Word Title;
} Object;

// Fungsi & Prosedur untuk tipe Song

void CreateEmptyLagu(Lagu *lagu);

Song CreateLagu(int PenyanyiID, int AlbumID, int PenyanyiID);

Word GetPenyanyi(TabKata *Penyanyi, int PenyanyiID);

Word GetAlbum(Map *Album, Map *Lagu, int PenyanyiID, int AlbumID);

Word GetLagu(Map *Album, Map *Lagu, int PenyanyiID, int AlbumID, int LaguID);

Word GetPlaylist(ArrayDinWord *PlaylistTitle, int PlaylistID);

boolean SongIsEqual(Song s1, Song s2);

void PrintSong(TabKata *Penyanyi, Map *Album, Map *Lagu, int PenyanyiID, int AlbumID, int LaguID);

// Fungsi & Prosedur untuk tipe Object

boolean ObjectIsEqual(Object o1, Object o2);

Object CreateObject(int ID, Word Title);

#endif