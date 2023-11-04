#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "boolean.h"

boolean cmprString(char *str1, char *str2) {
    int i = 0;
    boolean equal;
    while (str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0) {
        i++;
    }
    if (str1[i] == str2[i]) {
        equal = true;
    } else {
        equal = false;
    }

    return equal;
}

int parseCommand(char *str) {
    int n;
    if (cmprString(str, "Start")) {
        n = 1;
    } else if (cmprString(str, "Load")) {
        n = 2;
    } else if (cmprString(str, "Exit")) {
        n = 10;
    } else if (cmprString(str, "Help")) {
        n = 11;
    } else {
        n = -1;
    }
    
    return n;
}

int main() {
    int command;
    char input[20];
    boolean inSession = false;
    boolean running = true;
    printf("Welcome to WayangWave\n");
    printf("Type \"help\" for more information\n");

    do {
        
        scanf("%s", input);
        command = parseCommand(input);

        switch (command)
        {
        case 1:
        //  start();
            inSession = true;
            break;
        case 2:
        //  Load();
            inSession = false;
            break;
        case 3:

            break;
        case 4:
        
            break;
        case 5:
        
            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;    
        case 10:
            running = false;
            printf("Bye\n");
            break;
        case 11:
        //  Help();
            break;
        case -1:
        // invalid command
            printf("Command tidak diketahui\n");
            printf("Type \"help\" for more information\n");
            break;
        default:
            break;
        }
    } while(running);
  
}
