#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include "./ADT/Queue/queue.h"
#include "./ADT/Mesin/mesinkata.h"
#include "./ADT/Lagu/song.h"
#include "./ADT/List/array.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/List Berkait/listlinier.h"
#include "./ADT/List/arraydinword.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/Lagu/lagu.h"
#include "list.h"

void QueueSong(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu);

void QueuePlaylist(Queue *Antrian, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData);

void QueueSwap (Queue *Antrian, Word a, Word b, Map *Lagu);

void QueueRemove(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu, Word a);

void QueueClear(Queue *Antrian);

#endif
