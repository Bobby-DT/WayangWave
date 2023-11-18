#ifndef START_WAYANGWAVE_H
#define START_WAYANGWAVE_H

#include <stdio.h>
#include "parseConfig.h"

extern boolean stateWayangWave;

void start(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Lagu *Playing, int *currentPlaylist);

#endif
