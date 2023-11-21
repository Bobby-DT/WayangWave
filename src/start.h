#ifndef START_WAYANGWAVE_H
#define START_WAYANGWAVE_H

#include <stdio.h>
#include "parseConfig.h"

void start(Word configsrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing, boolean isLoad, boolean *wayangwaveStarted);

#endif
