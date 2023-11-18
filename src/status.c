#include "status.h"

void status(TabKata *Penyanyi, Queue *Antrian, Map *Album, Map *Lagu, ArrayDinWord *PlaylistTitle, Song *Playing) {
    if ((*Playing).PlaylistID != -1) {
        printf("Current Playlist: ");
        PrintWord(GetPlaylist(&PlaylistTitle, (*Playing).PlaylistID));
        printf("\n\n");
    }
    printf("Now Playing:\n");
    if ((*Playing).LaguID == NULL) {
        printf("No songs have been played yet. Please search for a song to begin playback.\n\n");
    } else {
        PrintSong(&Penyanyi, &Album, &Lagu, (*Playing).PenyanyiID, (*Playing).AlbumID, (*Playing).LaguID);
        printf("\n\n");
    }
    printf("Queue:\n");
    if (queue_isEmpty(*Antrian)) {
        printf("Your queue is empty.\n\n");
    } else {
        int idx = 1;
        if ((*Antrian).idxHead <= (*Antrian).idxTail) {
            for (int i = (*Antrian).idxHead; i <= (*Antrian).idxTail; i++) {
                printf("%d. ", idx);
                PrintSong(&Penyanyi, &Album, &Lagu, (*Antrian).buffer[i].PenyanyiID, (*Antrian).buffer[i].AlbumID, (*Antrian).buffer[i].LaguID);
                printf("\n");
                idx++;
            }
        } else {
            for (int i = (*Antrian).idxHead; i < CAPACITY; i++) {
                printf("%d. ", idx);
                PrintSong(&Penyanyi, &Album, &Lagu, (*Antrian).buffer[i].PenyanyiID, (*Antrian).buffer[i].AlbumID, (*Antrian).buffer[i].LaguID);
                printf("\n");
                idx++;
            }
            for (int i = 0; i <= (*Antrian).idxTail; i++) {
                printf("%d. ", idx);
                PrintSong(&Penyanyi, &Album, &Lagu, (*Antrian).buffer[i].PenyanyiID, (*Antrian).buffer[i].AlbumID, (*Antrian).buffer[i].LaguID);
                printf("\n");
                idx++;
            }
        }
        printf("\n");
    }
}