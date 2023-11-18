#ifndef PARSECONFIG_H
#define PARSECONFIG_H

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "./ADT/SetMap/Set/map.h"
#include "./ADT/SetMap/set.h"
#include "./ADT/Mesin/mesinKata.h"

void parseConfig(TabKata *Penyanyi, Map *mapPenyanyi, Map *mapAlbum);
/* Melakukan 'load' daftar Penyanyi, album dan lagu ke dalam program */

void copyStr(char *Str1, char *Str2);
/* copy str1 ke str2 */

int StringToInt(char *str, int length);
/* Mengembalikan hasil konversi String ke integer */

#endif
