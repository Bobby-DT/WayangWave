#ifndef QUIT_H
#define QUIT_H

#include <stdio.h>
#include "./ADT/Mesin/mesinkata.h"
#include "save.h"

void quit(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing, boolean *wayangwaveStarted);
/* 
Keluar dari aplikasi WayangWave
Program akan menyimpan file saat input "Y" atau "y"
*/

#endif /* QUIT_H */