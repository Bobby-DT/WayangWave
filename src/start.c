#include <stdio.h>
#include "start.h"

boolean stateWayangWave;

void start(Word configsrc, TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    // readConfig
    parseConfig(configsrc, *Penyanyi, *Album, *Lagu);
    if (!IsEmpty(*Penyanyi)) {
        if (!WordCompare(toKata("config.txt"), configsrc)) {
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        } else {
            printf("File konfigurasi sistem berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        }
        wayangwaveStarted = true;
    } else 
        if (!WordCompare(toKata("config.txt"), configsrc)) {
            printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n\n");
        } else {
            printf("File konfigurasi sistem gagal dibaca. Silahkan coba lagi.\n\n");
        }
        wayangwaveStarted = false;
    }
}
