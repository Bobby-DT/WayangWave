#include <stdio.h>
#include "start.h"

boolean stateWayangWave;

void start(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Lagu *Playing, int *currentPlaylist) {
    // readConfig
    parseConfig(Penyanyi, Album, Lagu);
    if (!IsEmpty(*Penyanyi)) {
        printf("File konfigurasi sistem berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        wayangwaveStarted = true;
    } else {
        wayangwaveStarted = false;
    }
}
