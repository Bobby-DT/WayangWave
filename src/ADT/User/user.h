#ifndef user_H
#define user_H

#include "../../boolean.h"
#include "../Mesin/mesinkata.h"
#include "../Lagu/song.h"
#include "../List/array.h"
#include "../Queue/queue.h"
#include "../Stack/stack.h"
#include "../SetMap/set.h"
#include "../SetMap/map.h"
#include "../List/arraydinword.h"
#include "../List/arraydin.h"
#include "../Lagu/lagu.h"

#define maxuser 20

typedef struct {
    Word Username;
    Song Playing;
    Queue Antrian;
    Stack Riwayat;
    ArrayDinWord PlaylistTitle;
    ArrayDin PlaylistData;
} UserData;

typedef struct {
    UserData storage[maxuser];
    int count; 
} UserStorage;

void initiateUserStorage(UserStorage *User);

int createNewUser(UserStorage *User, Word Username);

int searchUser(UserStorage *User, Word Username);

#endif
