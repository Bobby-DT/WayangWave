#ifndef song_H
#define song_H

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

void CreateEmptyLagu(Song *lagu);

Song CreateLagu(int PenyanyiID, int AlbumID, int LaguID, int PlaylistID);

boolean SongIsEqual(Song s1, Song s2);

// Fungsi & Prosedur untuk tipe Object

boolean ObjectIsEqual(Object o1, Object o2);

Object CreateObject(int ID, Word Title);

#endif