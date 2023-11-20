#ifndef lagu_H
#define lagu_H

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "song.h"
#include "../List/array.h"
#include "../List/arraydinword.h"
#include "../SetMap/set.h"
#include "../SetMap/map.h"

Word GetPenyanyi(TabKata *Penyanyi, int PenyanyiID);

Word GetAlbum(Map *Lagu, int AlbumID);

Word GetLagu(Map *Lagu, int AlbumID, int LaguID);

Word GetPlaylist(ArrayDinWord *PlaylistTitle, int PlaylistID);

int GetPenyanyiID(TabKata *Penyanyi, Word namaPenyanyi);

int GetAlbumID(Map *Album, Word namaAlbum, int PenyanyiID);

int GetLaguID(Map *Lagu, Word namaLagu, int AlbumID);

int GetPlaylistID(ArrayDinWord *PlaylistTitle, Word namaPlaylist);

void PrintSong(TabKata *Penyanyi, Map *Album, Map *Lagu, int PenyanyiID, int AlbumID, int LaguID);

#endif