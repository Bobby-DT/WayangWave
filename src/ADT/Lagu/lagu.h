#ifndef lagu_H
#define lagu_H

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"

typedef int IDtype;
typedef Word Titletype;
typedef struct {
    IDtype PenyanyiID;
    IDtype AlbumID;
    IDtype LaguID;
} Song;

typedef struct {
    IDtype ID;
    Titletype Title;
} Object;

// Fungsi & Prosedur untuk tipe Song

void CreateEmptyLagu(Lagu *lagu);

Song CreateLagu(IDtype PenyanyiID, IDtype AlbumID, IDtype PenyanyiID);

Word GetPenyanyi(TabKata *Penyanyi, int PenyanyiID);

Word GetAlbum(Map *Album, Map *Lagu, int PenyanyiID, int AlbumID);

Word GetLagu(Map *Album, Map *Lagu, int PenyanyiID, int AlbumID, int LaguID);

boolean SongIsEqual(Song s1, Song s2);

// Fungsi & Prosedur untuk tipe Object

boolean ObjectIsEqual(Object o1, Object o2);

Object CreateObject(IDtype ID, Titletype Title);

#endif