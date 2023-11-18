#include "help.h"
#include <string.h>

void help(int inSession){
    if (!inSession){
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
    else {
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. LIST -> Untuk menampilkan daftar lagu, playlist…\n");
        printf("2. PLAY -> Untuk memulai suatu lagu");
        printf("3. QUEUE -> \n");
        printf("4. SONG -> \n");
        printf("5. PLAYLIST -> \n");
        printf("6. STATUS -> \n");
        printf("7. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("8. QUIT -> Untuk keluar dari sesi\n");
    } 
} 

int main(){
    char command[100];
    int inSession;
    inSession = 0;

    printf("Masukkan perintah: ");
    scanf("%s", command);

    if (strcmp(command, "HELP;") == 0) {
        help(inSession);
    } 
    else {
        printf("Perintah tidak dikenali.\n");
    }

    return 0;
}