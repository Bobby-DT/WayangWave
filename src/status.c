#include "status.h"

void status(Queue *Antrian, Lagu *Playing, int *currentPlaylist) {
    if (*currentPlaylist != NULL) {
        printf("Current Playlist: ");
        TulisWord();
        printf("\n\n");
    }
    printf("Now Playing:\n");
    if (*Playing.LaguID == NULL) {
        printf("No songs have been played yet. Please search for a song to begin playback.\n\n");
    } else {
        TulisWord();
    }
    printf("Queue:\n");
    if (queue_isEmpty(*Antrian)) {
        printf("Your queue is empty.\n\n");
    } else {

    }
}