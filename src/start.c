#include <stdio.h>
#include "start.h"

boolean stateWayangWave;

void start(Word configsrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing, boolean isLoad, boolean *wayangwaveStarted) {
    // readConfig
    parseConfig(configsrc, Penyanyi, Antrian, Riwayat, Album, Lagu, PlaylistTitle, PlaylistData, Playing);
    if (!IsEmpty(*Penyanyi)) {
        if (!WordCompare(toKata("config.txt"), configsrc)) {
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        } else {
            printf("File konfigurasi sistem berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        }
        *wayangwaveStarted = true;
    } else {
        if (!isLoad) {
            printf("File konfigurasi sistem gagal dibaca. Silahkan coba lagi.\n\n");
        }
        *wayangwaveStarted = false;
    }
}