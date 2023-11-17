#include "parseConfig.h"

void parseConfig(TabKata *Penyanyi, Map *Album, Map *Lagu) {
    
    int i, j, k, numOfSinger, numOfAlbum, numOfSong;
    char namaPenyanyi[100], namaAlbum[100], namaLagu[100];
    Set setAlbum, setLagu;
    FILE* fptr;
    
    fptr = fopen("config.txt", "r");

    if (fptr == NULL) {
        printf("Error, file not opened.");
        exit(0);
    }


    start();
    numOfSinger = StringToInt(currentWord.TabWord, currentWord.Length);  // jumlah penyanyi
    
    for (i = 0; i < numOfSinger; i++) {

        adv(); // currentWord -> jumlah album
        numOfAlbum = StringToInt(currentWord.TabWord, currentWord.Length);  // jumlah album
        adv(); // currentWord -> nama penyanyi
        SetEl(Penyanyi, NbElmt(*Penyanyi), currentWord);
        
        copyStr(currentWord.TabWord, namaPenyanyi);

        CreateEmpty(&setAlbum);

        for (j = 0; j < numOfAlbum; j++) {

            adv(); // cKata -> jumlah lagu
            numOfSong = StringToInt(currentWord.TabWord, currentWord.Length);
            adv(); // cKata -> nama album
            copyStr(currentWord.TabWord, namaAlbum);

            CreateEmpty(&setLagu);

            for (k = 0; k < numOfSong; k++) {
                adv(); // cKata -> nama lagu
                add(&setLagu, currentWord.TabWord); // add ke set lagu
            }

            Insert(Lagu, namaAlbum, setLagu); // insert ke map Lagu

            add(&setAlbum, namaAlbum); // add nama album ke set Album
        }

        Insert(Album, namaPenyanyi, setAlbum); // insert set album ke map Album
    }
    

}

void copyStr(char *Str1, char *Str2) {
    /* Copy Str1 ke Str2 */
    int i;
    for (i = 0; Str1[i] != '\0'; i++) {
        Str2[i] = Str1[i];
    } 
    Str2[i] = '\0';
}

int StringToInt(char *str, int length) {
    int i;
    int num = 0;

    for (i = 0; i < length; i++) {
        num = num * 10 + (str[i] - '0');
    }

    return num;
}
