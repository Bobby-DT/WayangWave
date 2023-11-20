#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include "./ADT/Queue/queue.h"
#include "./ADT/Mesin/MesinKata.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/List/array.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/listBerkait/listlinier.h"
#include "./ADT/Lagu/song.h"
#include "./ADT/Lagu/lagu.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/List/arraydinword.h"
#include "list.h"

void QueueSong(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu);

void QueuePlaylist(Queue *Antrian, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Map *Lagu);

void QueueSwap (Queue *Antrian, Word a, Word b);

void QueueRemove(Queue *Antrian, Word a, Map *Lagu, TabKata *Penyanyi, Map *Album);

#endif