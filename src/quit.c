#include "quit.h"
#include <stdio.h>

void saveSession(){
    printf("Save file berhasil disimpan.\n");
}
void quit(){
    char response[2];
    printf("Apakah kamu ingin menyimpan data sesi sekarang?");
    scanf("%1s", response);

    if (strcmp(response, "Y") == 0 || strcmp(response, "y") == 0){
        saveSession();
        printf("Kamu keluar dari WayangWave.\nDdah ^_^\n");
    }
    else if (strcmp(response, "N") == 0 || strcmp(response, "n") == 0)
        printf("Kamu keluar dari WayangWave.\nDdah ^_^\n");
}

int main(){
    quit();
    return 0;
}
