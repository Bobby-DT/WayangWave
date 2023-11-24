#ifndef ENHANCE
#define ENHANCE

#include <stdio.h>
#include <time.h>
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

int randomInt(int max_num);

void addRandomSong(TabKata *Penyanyi, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, int PlaylistID, int playlistSongID, int *jumlahLaguRekomendasi);

void enhance(TabKata *Penyanyi, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData);

#endif