#include <stdio.h>
#include "start.h"

boolean stateWayangWave;

void start(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, ArrayDin *PlaylistData, Song *Playing) {
    // readConfig
    parseConfig(*Penyanyi, *Album, *Lagu);
    if (!IsEmpty(*Penyanyi)) {
        printf("File konfigurasi sistem berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
        wayangwaveStarted = true;
    } else {
        printf("File konfigurasi sistem gagal dibaca. Silahkan coba lagi.\n\n");
        wayangwaveStarted = false;
    }
}
