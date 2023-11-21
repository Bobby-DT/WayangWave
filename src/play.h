#ifndef listcommand_H
#define listcommand_H

#include <stdio.h>
#include "boolean.h"
#include "./ADT/Lagu/song.h"
#include "list.h"
#include "./ADT/List/array.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/SetMap/set.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/List/arraydinword.h"
#include "./ADT/List Berkait/listlinier.h"
#include "./ADT/Lagu/lagu.h"

void play(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing);

#endif