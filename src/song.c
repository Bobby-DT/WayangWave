#include "song.h"

void SongNext(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Lagu, Song *Playing) {
    if(!queue_isEmpty(*Antrian)){
        PushStack(&Riwayat, *Playing);
        Song nextSong;
        dequeue(&Antrian, &nextSong);
        *Playing = nextSong;

        printf("Memutar lagu selanjutnya\n\"");
        PrintWord(GetLagu(*Lagu, nextSong.AlbumID, nextSong.LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(*Penyanyi, nextSong.PenyanyiID));
        printf("\"\n");
    }
    else {
        printf("Queue kosong, memutar kembali lagu\n\"");
        PrintWord(GetLagu(*Lagu, (*Playing).AlbumID, (*Playing).LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(*Penyanyi, (*Playing).PenyanyiID));
        printf("\"\n");
    }
}

void SongPrevious(TabKata *Penyanyi, Queue *Antrian, Stack *Riwayat, Map *Lagu, Song *Playing) {
    if (!IsEmptyStack(*Riwayat)){
        Song previousSong;
        Pop(&Riwayat, &previousSong);
        queue_insert(&Riwayat, *Playing);
        *Playing = previousSong;

        printf("Memutar lagu sebelumnya\n\"");
        PrintWord(GetLagu(*Lagu, previousSong.AlbumID, previousSong.LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(*Penyanyi, previousSong.PenyanyiID));
        printf("\"\n");
    }
    else{
        printf("Riwayat lagu kosong, memutar kembali lagu\n\"");
        PrintWord(GetLagu(*Lagu, (*Playing).AlbumID, (*Playing).LaguID));
        printf("\" oleh \"");
        PrintWord(GetPenyanyi(*Penyanyi, (*Playing).PenyanyiID));
        printf("\"\n");
    }
}
