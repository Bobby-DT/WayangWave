#ifndef songcommand_H
#define songcommand_H

#include "boolean.h"
#include "./ADT/Lagu/song.h"
#include "./ADT/List/array.h"   
#include "./ADT/Queue/queue.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/Lagu/lagu.h"

void SongNext(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Lagu, Song *Playing);

void SongPrevious(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Lagu, Song *Playing);

#endif