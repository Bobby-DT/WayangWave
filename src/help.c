#include "help.h"

void help(boolean wayangwaveStarted){
    if (!wayangwaveStarted){
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
    else {
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. LIST -> Untuk menampilkan daftar lagu, playlist…\n");
        printf("2. PLAY -> Untuk memulai suatu lagu\n");
        printf("3. QUEUE -> Untuk menampilan antrian lagu\n");
        printf("4. SONG -> Untuk menampilkan lagu\n");
        printf("5. PLAYLIST -> Untuk menampilkan playlist\n");
        printf("6. STATUS -> Untuk menampilkan status\n");
        printf("7. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("8. QUIT -> Untuk keluar dari sesi\n");
    }
    printf("\n");
}