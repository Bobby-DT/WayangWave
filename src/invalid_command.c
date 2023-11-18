#include "invalid_command.h"

void invalidCommand(const char *command){
    if (strcmp(command, "LOAD filekonfigurasi.txt") == 0){
        printf("Command tidak bisa dieksekusi!\n");
    }
    else if (strcmp(command, "LIST DEFAULT") == 0){
        printf("Command tidak bisa dieksekusi!\n");
    }
    else {
        printf("Command tidak diketahui!\n");
    }
}

int main(){
    char command[100];
    printf("Masukkan perintah: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';
    invalidCommand(command);
    return 0;
}