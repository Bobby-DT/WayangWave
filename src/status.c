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
        for (int i = 0; i < queue_length(*Antrian); i++) {

        }
    }
}