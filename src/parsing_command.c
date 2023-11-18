#include <stdio.h>
#include "parsing_command.h"

int parsingCommand(char *input, char *command) {
    return sscanf(input, "%s", command);
}

int main() {
    char input[100]; // menyimpan input pengguna
    char command[20]; // menyimpan command

    printf("Masukkan command: ");
    fgets(input, sizeof(input), stdin);

    if (parsingCommand(input, command) == 1) {
        printf("Command: %s\n", command);
    } else {
        printf("Input tidak valid.\n");
    }

    return 0;
}

