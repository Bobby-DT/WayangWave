#ifndef PARSECONFIG_H
#define PARSECONFIG_H

#include "boolean.h"
#include "./ADT/Mesin/mesinKata.h"
#include "./ADT/Lagu/song.h"
#include "./ADT/List/array.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/SetMap/set.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/List/arraydinword.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/Lagu/lagu.h"

void GetIDfromConfig(TabKata *Penyanyi, Map *Album, Map *Lagu, int PlaylistID, Word failedAlert, Song *Result);

void parseConfig(Word filesrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing);
/* Melakukan 'load' daftar Penyanyi, album dan lagu ke dalam program */

#endif
