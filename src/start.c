#include <stdio.h>
#include "start.h"

boolean stateWayangWave;

void start(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *MapPenyanyi, Map *Album, MapPlaylist *Playlist) {
    // readConfig
    if (!IsEmpty(*Penyanyi)) {
        printf("File konfigurasi sistem berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        wayangwaveStarted = true;
    } else {
        wayangwaveStarted = false;
    }
}