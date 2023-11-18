#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include "../src/ADT/Queue/queue.h"
#include "../src/ADT/Mesin/MesinKata.h"
#include "../src/ADT/SetMap/map.h"
#include "../src/ADT/List/array.h"
#include "../src/ADT/Stack/stack.h"
#include "../src/ADT/listBerkait/listlinier.h"
#include "../src/ADT/Lagu/lagu.h"
#include "../src/ADT/List/arraydin.h
#include "../src/ADT/List/arraydinword.h"

void QueueSong(TabKata Penyanyi, Queue *Antrian, Map Album, Map lagu);

void QueuePlaylist(Queue *Antrian, ArrayDinWord PlaylistTitle, ArrayDin PlaylistData, Map lagu);

void QueueSwap (Queue *Antrian, Word a, Word b);

void QueueRemove(Queue *Antrian, Word a, Map lagu, TabKata Penyanyi, Map Album);

#endif