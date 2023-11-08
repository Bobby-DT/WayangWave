#include <stdio.h>
#include "start.h"

boolean stateWayangWave;

void start(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *MapPenyanyi, Map *Album, MapPlaylist *Playlist) {
    // readConfig
    if (!IsEmpty(*Penyanyi)) {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
        stateBNMO = true;
    } else {
        stateBNMO = false;
    }
}