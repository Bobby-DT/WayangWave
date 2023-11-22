#ifndef QUIT_H
#define QUIT_H

#include <stdio.h>
#include "./ADT/Mesin/mesinkata.h"
#include "save.h"

void quit(TabKata *Penyanyi, Map *Album, Map *Lagu, UserStorage *User, boolean *wayangwaveStarted, int UserID);
/* 
Keluar dari aplikasi WayangWave
Program akan menyimpan file saat input "Y" atau "y"
*/

#endif /* QUIT_H */