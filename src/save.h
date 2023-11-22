#ifndef save_H
#define save_H

#include "boolean.h"
#include "./ADT/Mesin/mesinkata.h"
#include "./ADT/Lagu/song.h"
#include "./ADT/List/array.h"
#include "./ADT/Queue/queue.h"
#include "./ADT/Stack/stack.h"
#include "./ADT/SetMap/set.h"
#include "./ADT/SetMap/map.h"
#include "./ADT/List/arraydinword.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/Lagu/lagu.h"
#include "./ADT/User/user.h"

void save(Word filesrc, TabKata *Penyanyi, Map *Album, Map *Lagu, UserStorage *User, int UserID);

#endif
