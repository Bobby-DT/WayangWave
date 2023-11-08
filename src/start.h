#ifndef START_WAYANGWAVE_H
#define START_WAYANGWAVE_H

#include <stdio.h>
#include "./driver/readConfig.h"

extern boolean stateWayangWave;

void start(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *MapPenyanyi, Map *Album, Set *PlaylistTitle, List *PlaylistData);

#endif