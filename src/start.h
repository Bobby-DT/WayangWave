#ifndef START_WAYANGWAVE_H
#define START_WAYANGWAVE_H

#include <stdio.h>
#include "parseConfig.h"

extern boolean wayangwaveStarted;

void start(Word configsrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing);

#endif
