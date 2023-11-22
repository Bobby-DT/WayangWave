#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#include "./ADT/Mesin/mesinkarakter.h"
#include "./ADT/Mesin/mesinkata.h"
#include "./ADT/Lagu/song.h"
#include "./ADT/Lagu/lagu.h"
#include "./ADT/List/array.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/List/arraydinword.h"
#include "./ADT/List Berkait/listlinier.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/SetMap/set.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/Stack/stack.h"

#include "help.h"
#include "list.h"
#include "parseConfig.h"
#include "play.h"
#include "playlist.h"
#include "queue.h"
#include "quit.h"
#include "save.h"
#include "song.h"
#include "start.h"
#include "status.h"

void menu(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing, boolean *wayangwaveStarted, boolean *quitAfterLoaded, UserStorage *User, int UserID);