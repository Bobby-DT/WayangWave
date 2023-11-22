#include <stdio.h>
#include "user.h"

void initiateUserStorage(UserStorage *User) {
    (User)->count = 0;
}

int createNewUser(UserStorage *User, Word Username) {
    int UserID = (*User).count + 1;

    Queue Antrian;
    Stack Riwayat;
    ArrayDinWord PlaylistTitle;
    ArrayDin PlaylistData;
    Song Playing;

    CreateQueue(&Antrian);
    CreateEmptyStack(&Riwayat);
    PlaylistTitle = MakeArrayDinWord();
    PlaylistData = MakeArrayDin();
    CreateEmptyLagu(&Playing);

    (User)->storage[UserID - 1].Username = Username;
    (User)->storage[UserID - 1].Playing = Playing;
    (User)->storage[UserID - 1].Antrian = Antrian;
    (User)->storage[UserID - 1].Riwayat = Riwayat;
    (User)->storage[UserID - 1].PlaylistTitle = PlaylistTitle;
    (User)->storage[UserID - 1].PlaylistData = PlaylistData;
    (User)->count++;

    return UserID;
}

int searchUser(UserStorage *User, Word Username) {
    for (int i = 0; i < (*User).count; i++) {
        if (WordCompare((*User).storage[i].Username, Username)) {
            return i+1;
        }
    }
    return -1;
}