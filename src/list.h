#ifndef LIST_WAYANGWAVE_H
#define LIST_WAYANGWAVE_H

#include "boolean.h"
#include "./ADT/Lagu/song.h" 
#include "./ADT/List/array.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/List/arraydinword.h"
#include "./ADT/Lagu/lagu.h"

void PrintDaftarPenyayi(TabKata *Penyanyi);

void PrintDaftarAlbum(TabKata *Penyanyi, Map *Album, int PenyanyiID);

void PrintDaftarLagu(TabKata *Penyanyi, Map *Album, Map *Lagu, int PenyanyiID, int AlbumID);

void ListDefault(TabKata *Penyanyi, Map *Album, Map *Lagu);

void ListPlaylist(ArrayDinWord *PlaylistTitle);

#endif