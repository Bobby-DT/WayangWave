#include <stdio.h>
#include "start.h"

void start(Word configsrc, TabKata *Penyanyi, Map *Album, Map *Lagu, UserStorage *User, Object *currentUser, boolean isLoad, boolean *isConfigLoaded) {
    // readConfig
    parseConfig(configsrc, Penyanyi, Album, Lagu, User);
    if (!IsEmpty(*Penyanyi)) {
        /*
        Variabel isLoad digunakan untuk mengetahui command yang digunakan
        isLoad = true -> LOAD <filename>
        isLoad = false -> START
        */
        if (isLoad) {
            printf("Save file berhasil dibaca. Lakukan Login untuk menjalankan WayangWave.\n\n");
        } else {
            printf("File konfigurasi sistem berhasil dibaca. Lakukan Login untuk menjalankan WayangWave.\n\n");
        }
        *isConfigLoaded = true;

    } else {
        if (isLoad) {
            printf("Save file gagal dibaca. Silahkan coba lagi.\n\n");
        } else {
            printf("File konfigurasi sistem gagal dibaca. Silahkan coba lagi.\n\n");
        }
        *isConfigLoaded = false;
    }
}